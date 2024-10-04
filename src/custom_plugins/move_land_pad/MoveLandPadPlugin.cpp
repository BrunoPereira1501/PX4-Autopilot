#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>

namespace gazebo
{
  class MoveLandPad : public ModelPlugin
  {
  public: 
    void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model
      this->model = _parent;

      // Listen to the update event. This event is broadcast every
      // simulation iteration.
      this->updateConnection = event::Events::ConnectWorldUpdateBegin(
          std::bind(&MoveLandPad::OnUpdate, this));
    }

    // Called by the world update start event
    public: void OnUpdate()
    {
      // Set a linear velocity
      this->model->SetLinearVel(ignition::math::Vector3d(1, 0, 0)); // Move along the x-axis
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(MoveLandPad)
}

