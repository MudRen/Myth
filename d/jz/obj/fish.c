//Cracked by Roath
inherit ITEM;

string *names = ({
  "[33mСϺ��[m",
  "[31mС����[m",
  "[32mС���[m",
  "[33m����[m",
  "[34mС��[m",
  "[35mС��[m",
  "[36mС����[m",
});

string *ids = ({
    "xiao xiami",
    "xiao yumiao",
    "xiao kedou",
    "bei ke",
    "xiao yu",
    "xiao she",
    "xiao wuzei",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i],"fish"}));
  set("unit","��");
  set("value",50);
  setup();
}
