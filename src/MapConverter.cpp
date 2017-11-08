
/*
 * Copyright (c) 2017
 *     Leonardo Baroncelli, Giancarlo Zollino
 *
 * Any information contained in this software
 * is property of the AGILE TEAM and is strictly
 * private and confidential.
 * 
 * https://github.com/Leofaber/MapConverter
*/

#include "MapConverter.h"


MapConverter::MapConverter() {
	
		
}


double ** MapConverter::mapPathToDoublePtr(const char * imagePath)
{
	
	double ** image;
	int rows = 0;
	int cols = 0;
	
	//CFITSIO
	fitsfile *fptr;   /* FITS file pointer, defined in fitsio.h */
	int status = 0;   /* CFITSIO status value MUST be initialized to zero! */
	int bitpix, naxis, ii, anynul;
	long naxes[2] = { 1, 1 }, fpixel[2] = { 1, 1 };
	double *pixels;
	char format[20], hdformat[20];
	
	if (!fits_open_file(&fptr, imagePath, READONLY, &status))
	{									// 16   , 2     , {166,166}
		if (!fits_get_img_param(fptr, 2, &bitpix, &naxis, naxes, &status))
		{
			rows = (int)naxes[0];
			cols = (int)naxes[1];
			image = new double*[rows];
			for (int i = 0; i < rows; ++i){
				image[i] = new double[cols];
			}
			if (naxis > 2 || naxis == 0)
			{	
				fprintf( stderr, "[MapConverter] ERROR 1 - only 1D or 2D images are supported");
				exit(EXIT_FAILURE);
			}			
			else
			{	 
				/* get memory for 1 row */
				pixels = (double *)malloc(naxes[0] * sizeof(double));

				if (pixels == NULL)
				{
					fprintf( stderr, "[MapConverter] ERROR 2 - Memory allocation error");
					exit(EXIT_FAILURE);
				}
				else
				{
					/* loop over all the rows in the image, top to bottom */

					int col_index = 0;
					int row_index = 0;
					for (fpixel[1] = naxes[1]; fpixel[1] >= 1; fpixel[1]--)
					{
						if (fits_read_pix(fptr, TDOUBLE, fpixel, naxes[0], NULL, pixels, NULL, &status))  /* read row of pixels */
							break;  /* jump out of loop on error */

						for (ii = 0; ii < naxes[0]; ii++)
						{
							
							image[row_index][col_index] = (double)pixels[ii];



							col_index++;
 
						}
						col_index = 0;
						row_index++;
					}

					free(pixels);
				}
			}

		}

		fits_close_file(fptr, &status);

	}
	if (status>0)
	{
		fprintf( stderr, "[MapConverter] ERROR %d",status);
		exit (EXIT_FAILURE);
		
	}

 	return image;

}

 bool MapConverter::addAgileMandatoryFitsKeys(const char * imagePath)
{
	std::string newFileName(imagePath);
	
 	size_t foundPatternFits = newFileName.find(".fits");
	
	if(foundPatternFits!=std::string::npos) {
		std::cout << ".fits trovato" << std::endl;
		double temp = 0;
		
		FitsFile fits(imagePath,READWRITE);
		if(!fits.ReadKey("MINENG", &temp)){
			std::cout << "MINEND NON TROVATA" << std::endl;
			fits.WriteKey("MINENG",0,0); 		//const char* name, double value, const char* comment=0	
		}else
			std::cout << "MINENG TROVATA!" << std::endl;
		
		/*
		f.ReadKey("CDELT1", &m_xbin);
		f.ReadKey("CRPIX1", &m_x0);
		f.ReadKey("CDELT2", &m_ybin);
		f.ReadKey("CRPIX2", &m_y0);
		f.ReadKey("CRVAL1", &m_la2);
		f.ReadKey("CRVAL2", &m_ba2);
		f.ReadKey("LONPOLE", &m_lonpole);
		f.ReadKey("MINENG", &m_emin);
		*/
		
		fits.Close();
	}
	
}






