#include "ImageHistogram.h"
#include "qcustomplot.h"


/*******************************************************************************************************************************/
/* Simple contrast improvement */
/*******************************************************************************************************************************/
void simpleContrastImprovement (const uchar input[], int xSize, int ySize, uchar output[])
{
	/* TODO */
}


/*******************************************************************************************************************************/
/* Calculate image histogram */
/*******************************************************************************************************************************/
void calculateHistogram(const uchar input[], int xSize, int ySize, int histogram[])
{
	/* TODO */
}


/*******************************************************************************************************************************/
/* Equalize image histogram */
/*******************************************************************************************************************************/
void equalizeHistogram(const uchar input[], int xSize, int ySize, uchar output[])
{
	/* TODO */
}

/*******************************************************************************************************************************/
/* Modify colour saturation */
/*******************************************************************************************************************************/
void modifySaturation(const uchar inputRGB[], const uchar inputY[], int xSize, int ySize, uchar outputRGB[], double S)
{
	/* TODO */
}

/*******************************************************************************************************************************/
/* Plot image histogram */
/* Returns QImage containing graph with histogram data. */
/* start and end parameters define first and last value for X axis */
/*******************************************************************************************************************************/
QImage createHistogramPlot(int histogram[], int start, int end)
{
	 QCustomPlot& customPlot = QCustomPlot();
	 
	 int vectorSize = end-start+1;
	 int maxValue = 0;
	 QVector<double> x(vectorSize), y(vectorSize);
	 for (int i=0; i<vectorSize; i++)
	 {
	   x[i] = i + start;  
	   y[i] = histogram[i];
	   maxValue = maxValue>=histogram[i]?maxValue:histogram[i];
	 }
	 
	 // create graph and assign data to it:
	 customPlot.addGraph();
	 customPlot.graph(0)->setData(x, y);
	 // give the axes some labels:
	 customPlot.xAxis->setLabel("x");
	 customPlot.yAxis->setLabel("y");
	 // set axes ranges, so we see all data:
	 customPlot.xAxis->setRange(start, end);
	 customPlot.yAxis->setRange(0, maxValue);
	 return customPlot.toPixmap().toImage();
}


