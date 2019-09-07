// Movement (b, w, e, G, gg, $, 0, })
// Normal->Insert (i, a, I, A, o, O)
// removing/changing text (dd, D, cc, C, r, R)



// TODO change wheelz to wheels (find and replace)
std::unique_ptr<Wheel_Kinematics> get_wheel_kinematics(int enables[NUM_WHEELS])
{

    struct wheel_info wheelz_info[NUM_WHEELS];

    // TODO convert back to . operator (ctrl+v [visual block], c)
    wheelz_info[0]->conf.x_pos   =  0.21;        // X position of the wheel
    wheelz_info[0]->conf.y_pos   =  0.21;        // Y position of the wheel
    wheelz_info[0]->conf.wheel_r =  5e-2;        // wheel radius
    wheelz_info[0]->conf.piv_off =  1e-2;        // pivot offset
    wheelz_info[0]->conf.wheel_d =  8e-2;        // distance between wheelz
    wheelz_info[0]->status.delta =  0;           // pivot angle

    wheelz_info[1]->conf.x_pos   = -0.21;
    wheelz_info[1]->conf.y_pos   =  0.21;
    wheelz_info[1]->conf.wheel_r =  5e-2;
    wheelz_info[1]->conf.piv_off =  1e-2;
    wheelz_info[1]->conf.wheel_d =  8e-2;
    wheelz_info[1]->status.delta =  M_PI/2.0;

    wheelz_info[2]->conf.x_pos   = -0.21;
    wheelz_info[2]->conf.y_pos   = -0.21;
    wheelz_info[2]->conf.wheel_r =  5e-2;
    wheelz_info[2]->conf.piv_off =  1e-2;
    wheelz_info[2]->conf.wheel_d =  8e-2;
    wheelz_info[2]->status.delta =  M_PI;

    // TODO add another wheel info (shift+v [visual line], p)


    // TODO make a for loop for setting enables (dd, p, >>, find and replace)


    // TODO better debug statement (ci")
    std::cout << "DeBuG StAtEmEnT: HeRe" << std::endl;


    // TODO add missing ; (A)
    // TODO change parameter order (yiw, viwp, p)
    return std::make_unique<Wheel_Kinematics>(NUM_WHEELS, wheelz_info)
}

// TODO convert the rest into constants
static const std::string NATO_A = "ALPHA";
Bravo, Charlie, Delta, Echo, Foxtrot, Golf, Hotel, India, Juliett, Kilo, Lima, Mike, November, Oscar, Papa, Quebec, Romeo, Sierra, Tango, Uniform, Victor, Whiskey, Xray, Yankee, Zulu
