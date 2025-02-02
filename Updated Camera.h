// Fortnites Latest Update ++Fortnite+Release-33.30-CL-39435251-Windows
// Date Of Update: 02/01/2025

Camera get_view_point()
{
    Camera view_point{};
    uintptr_t location_pointer = read<uintptr_t>(cache::uworld + 0x130); // This Was Updated.
    uintptr_t rotation_pointer = read<uintptr_t>(cache::uworld + 0x140); // And This.
    FNRot fnrot{};
    fnrot.a = read<double>(rotation_pointer);
    fnrot.b = read<double>(rotation_pointer + 0x20);
    fnrot.c = read<double>(rotation_pointer + 0x1D0);
    view_point.location = read<Vector3>(location_pointer);
    view_point.rotation.x = asin(fnrot.c) * (180.0 / M_PI);
    view_point.rotation.y = ((atan2(fnrot.a * -1, fnrot.b) * (180.0 / M_PI)) * -1) * -1;
    auto fov_radians = read<float>(cache::player_controller + 0x3AC) * 2;
    view_point.fov * 180.0f / std::numbers::pi;
    return view_point;
}
