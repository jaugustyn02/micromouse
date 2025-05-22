#ifndef MICROMOUSE_INCLUDE_MODEL_MOVESTATUS_H_
#define MICROMOUSE_INCLUDE_MODEL_MOVESTATUS_H_

/**
 * @brief The MoveStatus enum class represents the status of a move operation.
 * It is used to indicate the result of a move attempt in the micromouse simulation.
 */
enum MoveStatus {
  SUCCESS,
  GOAL_REACHED,
  FAILURE,
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOVESTATUS_H_
