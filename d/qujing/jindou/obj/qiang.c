
#include <weapon.h>

inherit SPEAR;

void create()
{
  set_name("���ǹ", ({"diangang qiang", "qiang", "spear"}));
  set_weight(4000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "����һ�ѵ��ǹ�����������ϻ������뺣��\n");
    set("value", 500);
    set("material", "iron");
    set("wield_msg", "$Nһ�С�����ں����ó�һ��$nͦ�����С�\n");
    set("unwield_msg", "$N�������е�$n��\n");
  }

  init_spear(55);
  setup();
}

