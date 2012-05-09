/*=========================================================================
 *
 *  Copyright RTK Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef __rtkSheppLoganPhantomFilter_h
#define __rtkSheppLoganPhantomFilter_h

#include <itkInPlaceImageFilter.h>
#include "rtkThreeDCircularProjectionGeometry.h"
#include "rtkRayQuadricIntersectionImageFilter.h"

#include "rtkThreeDCircularProjectionGeometryXMLFile.h"
#include "rtkRayEllipsoidIntersectionImageFilter.h"

#include <vector>

namespace rtk
{

/** \class SheppLoganPhantomFilter
 * \brief Computes intersection of projection rays with ellipsoids.
 * in order to create a Shepp-Logan phantom projections.
 */

template <class TInputImage, class TOutputImage>
class ITK_EXPORT SheppLoganPhantomFilter :
  public RayEllipsoidIntersectionImageFilter<TInputImage,TOutputImage>
{
public:
  /** Standard class typedefs. */
  typedef SheppLoganPhantomFilter                                       Self;
  typedef RayEllipsoidIntersectionImageFilter<TInputImage,TOutputImage> Superclass;
  typedef itk::SmartPointer<Self>                                       Pointer;
  typedef itk::SmartPointer<const Self>                                 ConstPointer;
  typedef typename TOutputImage::RegionType               OutputImageRegionType;
  typedef typename TOutputImage::Superclass::ConstPointer OutputImageBaseConstPointer;

  typedef float OutputPixelType;

  typedef itk::Image< OutputPixelType, 3 >                                           OutputImageType;
  typedef rtk::RayEllipsoidIntersectionImageFilter<OutputImageType, OutputImageType> REIType;
  typedef std::vector<double>                                                        VectorType;
  typedef std::string                                                                StringType;
  typedef std::vector< std::vector<double> >                                         VectorOfVectorType;
  typedef SetQuadricParamFromRegularParamFunction                                    SQPFunctionType;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(SheppLoganPhantomFilter, RayEllipsoidIntersectionImageFilter);

  /** Get/Set Number of Figures.*/
  itkSetMacro(ConfigFile, StringType);
  itkGetMacro(ConfigFile, StringType);

  rtkSetMacro(Fig, VectorOfVectorType);
  rtkGetMacro(Fig, VectorOfVectorType);

protected:
  SheppLoganPhantomFilter() {}
  virtual ~SheppLoganPhantomFilter() {};

  virtual void GenerateData();
  //void Config();

  /** Translate user parameteres to quadric parameters.
   * A call to this function will assume modification of the function.*/


private:
  SheppLoganPhantomFilter(const Self&); //purposely not implemented
  void operator=(const Self&);            //purposely not implemented

  VectorOfVectorType       m_Fig;
  StringType               m_ConfigFile;
  SQPFunctionType::Pointer m_SQPFunctor;
};

} // end namespace rtk

#ifndef ITK_MANUAL_INSTANTIATION
#include "rtkSheppLoganPhantomFilter.txx"
#endif

#endif