// color.c

// filter color
string filter_color(string arg)
{
    return COLOR_D->clean_color(arg);
}

// trans_color
// raw = 0, only forecolor
// raw = 1, include backround color
// raw = 2, include blink & others
string trans_color(string arg, int raw)
{
    return COLOR_D->trans_color(arg, raw);
}

// color filter
string color_filter(string str)
{
    if (!str)
        return "";

   return COLOR_D->trans_color(str, 2);
}

// color cat
void color_cat(string file)
{
    if (previous_object())
        seteuid(geteuid(previous_object()));
    else
        seteuid(ROOT_UID);

    write(color_filter(read_file(file)));
}

// append color after the $N��$n��$w for the string color won't be
// break by the NOR after the name
string append_color(string arg, string default_color)
{
    arg = replace_string(arg, "$N", "$N" + default_color);
    arg = replace_string(arg, "$n", "$n" + default_color);
    arg = replace_string(arg, "$w", "$w" + default_color);
    return arg;
}