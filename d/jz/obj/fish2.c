//Cracked by Roath
inherit ITEM;

string *names = ({
  "[32mСϺ��[m",
  "[32mС����[m",
  "[36mС���[m",
  "[35m����[m",
  "[34mС��[m",
  "[33mС��[m",
  "[32mС����[m",
  "[31m������[m",
  "[36m����[m",
  "[32m����[m",
  "[33m����[m",
  "[34m����[m",
  "[1;30m����[m",
  "[1;36m����[m",
  "[35m����[m",
});

string *ids = ({
    "xiao xiami",
    "xiao yumiao",
    "xiao kedou",
    "bei ke",
    "xiao yu",
    "xiao she",
    "xiao wuzei", 
   "li yu",
    "cao yu",
    "nian yu",
    "ji yu",
    "lian yu",
    "hei yu",
    "jin yu",
    "shi yu",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("unit","��");
  set("value",100);
  setup();
}
