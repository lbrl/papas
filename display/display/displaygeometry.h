//
//  Created by Alice Robson on 29/11/15.
//
//
#ifndef  DISPLAY_DETECTOR_H
#define DISPLAY_DETECTOR_H

#include <map>
#include <string>
#include <memory>
#include "TEllipse.h"
#include "TBox.h"
#include "TColor.h"
#include "detector.h"


namespace papas {
  
/// This is the base class used for other elements that are to be drawn.
/// The key thing is to have the Draw element
class Drawable {
public:
   Drawable();
   virtual void Draw(const std::string& projection) const = 0;
private:

};

/// Class to draw the HCAL and ECAL detectors
class GDetectorElement : public Drawable {
public:
   GDetectorElement(std::shared_ptr<const DetectorElement> de);
   //GDetectorElement(const DetectorElement& de);
   void Draw(const std::string& projection) const override;
private:
   ///Shared_ptr to the detector element
   std::shared_ptr<const DetectorElement> m_detElem;
   //const DetectorElement & m_detElem;

   ///lists of shared_pointer  to circles to be used to plot the detector element
   std::list<std::unique_ptr<TEllipse>> m_circles;

   ///lists of shared_pointer  to boxes to be used to plot the detector element
   std::list<std::unique_ptr<TBox>> m_boxes;
};

///Graphical representation of the detector - holds all the GDetectorElements together
class GDetector: public Drawable {
public:
   GDetector(const Detector& detector);
   void Draw(const std::string& projection) const override;
private:
   ///ECAL graphical detector element
   GDetectorElement m_gEcal;

   ///HCAL graphical detector element
   GDetectorElement m_gHcal;
   /// will contain shared_ptrs to GDetectorElements and GTrajectories to be plotted

   std::list<std::shared_ptr<Drawable>> m_drawElems;

};
} // end namespace papas


#endif