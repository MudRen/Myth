//Cracked by Roath
static mapping opp_dir = ([
  "east"        :       "west",
  "west"        :       "east",
  "north"       :       "south",
  "south"       :       "north",
  "northeast"   :       "southwest",
  "southwest"   :       "northeast",
  "northwest"   :       "southeast",
  "southeast"   :       "northwest",
  "northup"     :       "southdown",
  "southup"     :       "northdown",
  "eastup"      :       "westdown",
  "westup"      :       "eastdown",
  "northdown"   :       "southup",
  "southdown"   :       "northup",
  "eastdown"    :       "westup",
  "westdown"    :       "eastup",
  "up"          :       "down",
  "down"        :       "up",
]);

static mapping chinese_dir = ([
        "north":                "����",
        "south":                "�ϱ�",
        "east":                 "����",
        "west":                 "����",
        "northup":              "���Ϸ�",
        "southup":              "���Ϸ�",
        "eastup":               "���Ϸ�",
        "westup":               "���Ϸ�",
        "northdown":        "���·�",
        "southdown":        "���·�",
        "eastdown":             "���·�",
        "westdown":             "���·�",
        "northeast":        "������",
        "northwest":        "������",
        "southeast":        "���Ϸ�",
        "southwest":        "���Ϸ�",
        "up":                   "����",
        "down":                 "����",
        "out":                  "����",
]);

static mapping abbr_dir = ([
        "n"     :       "north",
        "s"     :       "south",
        "e"     :       "east",
        "w"     :       "west",
        "nu"    :       "northup",
        "su"    :       "southup",
        "eu"    :       "eastup",
        "wu"    :       "westup",
        "nd"    :       "northdown",
        "sd"    :       "southdown",
        "ed"    :       "eastdown",
        "wd"    :       "westdown",
        "ne"    :       "northeast",
        "nw"    :       "northwest",
        "se"    :       "southeast",
        "sw"    :       "southwest",
        "u"     :       "up",
        "d"     :       "down",
        "o"     :       "out",
]);

string abbrdir(string dir)
{
  if (!undefinedp(abbr_dir[dir]))
    return abbr_dir[dir];
  else
    return dir;
}

string cdir(string dir)
{
  dir = abbrdir(dir);
  if (!undefinedp(chinese_dir[dir]))
    return chinese_dir[dir];
  else return dir;
}

string oppdir(string dir)
{
  if (!undefinedp(opp_dir[dir]))
    return opp_dir[dir];
  else
    return "";
}
