//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

string *names = ({
  "[33m�ϻ���[m",
  "[31m�����[m",
  "[32m������[m",
  "[33m������[m",
  "[34m����[m",
  "[35m¹��[m",
});

string *ids = ({
    "laohu rou",
    "xiangzhang rou",
    "mangshe rou",
    "huli rou",
    "tu rou",
    "lu rou",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set_weight(80);
      if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���������Ѭ�⡣\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 30);
        }
}

