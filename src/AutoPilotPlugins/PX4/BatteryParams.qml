/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.2

import QGroundControl 1.0
import QGroundControl.FactSystem 1.0
import QGroundControl.FactControls  1.0
import QGroundControl.Controls  1.0



// Exposes the set of battery parameters taking into account the availability of the parameters.
// Only the _SOURCE parameter can be assumed to be always available. The remainder of the parameters
// may or may not be available depending on the _SOURCE setting.
QtObject {
    property var controller     ///< FactPanelController
    property int batteryIndex   ///< 1-based battery index

    property Fact battSource:                   controller.getParameterFact(-1, "BAT#_SOURCE".replace       ("#", batteryIndex))
    property Fact battNumCells:                 controller.getParameterFact(-1, "BAT#_N_CELLS".replace      ("#", batteryIndex), false)
    property Fact battHighVolt:                 controller.getParameterFact(-1, "BAT#_V_CHARGED".replace    ("#", batteryIndex), false)
    property Fact battLowVolt:                  controller.getParameterFact(-1, "BAT#_V_EMPTY".replace      ("#", batteryIndex), false)
    property Fact battVoltLoadDrop:             controller.getParameterFact(-1, "BAT#_V_LOAD_DROP".replace  ("#", batteryIndex), false)
    property Fact battVoltageDivider:           controller.getParameterFact(-1, "BAT#_V_DIV".replace        ("#", batteryIndex), false)
    property Fact battAmpsPerVolt:              controller.getParameterFact(-1, "BAT#_A_PER_V".replace      ("#", batteryIndex), false)

    property bool battNumCellsAvailable:        controller.parameterExists(-1, "BAT#_N_CELLS".replace       ("#", batteryIndex))
    property bool battHighVoltAvailable:        controller.parameterExists(-1, "BAT#_V_CHARGED".replace     ("#", batteryIndex))
    property bool battLowVoltAvailable:         controller.parameterExists(-1, "BAT#_V_EMPTY".replace       ("#", batteryIndex))
    property bool battVoltLoadDropAvailable:    controller.parameterExists(-1, "BAT#_V_LOAD_DROP".replace   ("#", batteryIndex))
    property bool battVoltageDividerAvailable:  controller.parameterExists(-1, "BAT#_V_DIV".replace         ("#", batteryIndex))
    property bool battAmpsPerVoltAvailable:     controller.parameterExists(-1, "BAT#_A_PER_V".replace       ("#", batteryIndex))
}
