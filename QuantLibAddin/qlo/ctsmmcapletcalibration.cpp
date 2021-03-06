/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2006, 2007 Ferdinando Ametrano
 Copyright (C) 2007 Chiara Fornarola
 Copyright (C) 2006, 2007 Marco Bianchetti
 Copyright (C) 2006, 2007 Cristina Duminuco
 Copyright (C) 2006, 2007 Giorgio Facchinetti

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#if defined(HAVE_CONFIG_H)     // Dynamically created by configure
    #include <qlo/config.hpp>
#endif
#include <qlo/ctsmmcapletcalibration.hpp>
#include <ql/models/marketmodels/models/alphaform.hpp>
#include <ql/models/marketmodels/models/capletcoterminalswaptioncalibration.hpp>
#include <ql/models/marketmodels/models/capletcoterminalalphacalibration.hpp>
#include <ql/models/marketmodels/models/capletcoterminalmaxhomogeneity.hpp>

namespace QuantLibAddin {

    CTSMMCapletOriginalCalibration::CTSMMCapletOriginalCalibration(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::EvolutionDescription& evolution,
            const boost::shared_ptr<QuantLib::PiecewiseConstantCorrelation>& corr,
            const std::vector<boost::shared_ptr<QuantLib::PiecewiseConstantVariance> >& swapVariances,
            const std::vector<QuantLib::Volatility>& capletVols,
            const boost::shared_ptr<QuantLib::CurveState>& cs,
            QuantLib::Spread displacement,
            const std::vector<QuantLib::Real>& alpha,
            bool lowestRoot,
            bool useFullApprox,
            bool permanent) : CTSMMCapletCalibration(properties, permanent)
    {
        libraryObject_ =
            boost::shared_ptr<QuantLib::CTSMMCapletCalibration>(new
                QuantLib::CTSMMCapletOriginalCalibration(
                    evolution, corr, swapVariances, capletVols, cs,
                    displacement, alpha, lowestRoot, useFullApprox));
    }

    CTSMMCapletAlphaFormCalibration::CTSMMCapletAlphaFormCalibration(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::EvolutionDescription& evolution,
            const boost::shared_ptr<QuantLib::PiecewiseConstantCorrelation>& corr,
            const std::vector<boost::shared_ptr<QuantLib::PiecewiseConstantVariance> >& swapVariances,
            const std::vector<QuantLib::Volatility>& capletVols,
            const boost::shared_ptr<QuantLib::CurveState>& cs,
            QuantLib::Spread displacement,
            const std::vector<QuantLib::Real>& alphaInitial,
            const std::vector<QuantLib::Real>& alphaMax,
            const std::vector<QuantLib::Real>& alphaMin,
            bool maximizeHomogeneity,
            boost::shared_ptr<QuantLib::AlphaForm>& parametricForm,
            bool permanent) : CTSMMCapletCalibration(properties, permanent)
    {
        libraryObject_ =
            boost::shared_ptr<QuantLib::CTSMMCapletCalibration>(new
                QuantLib::CTSMMCapletAlphaFormCalibration(
                    evolution, corr, swapVariances, capletVols, cs,
                    displacement, alphaInitial, alphaMax, alphaMin,
                    maximizeHomogeneity, parametricForm));
    }

    CTSMMCapletMaxHomogeneityCalibration::CTSMMCapletMaxHomogeneityCalibration(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::EvolutionDescription& evolution,
            const boost::shared_ptr<QuantLib::PiecewiseConstantCorrelation>& corr,
            const std::vector<boost::shared_ptr<QuantLib::PiecewiseConstantVariance> >& swapVariances,
            const std::vector<QuantLib::Volatility>& capletVols,
            const boost::shared_ptr<QuantLib::CurveState>& cs,
            QuantLib::Spread displacement,
            QuantLib::Real caplet0Swaption1Priority,
            bool permanent) : CTSMMCapletCalibration(properties, permanent)
    {
        libraryObject_ =
            boost::shared_ptr<QuantLib::CTSMMCapletCalibration>(new
                QuantLib::CTSMMCapletMaxHomogeneityCalibration(
                    evolution, corr, swapVariances, capletVols, cs,
                    displacement, caplet0Swaption1Priority));
    }

}

