// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit HEAD;

string *names = ({
  "��ͷ��",
});

string *ids = ({
  "tie tou kui",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "tou kui", "kui", "head"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
   set("value", 200);
   set("material", "metal");
   set("armor_prop/armor", 12);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}

