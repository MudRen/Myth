// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// ���ְ� huanlebang.c
// lizuole 99.12.16

#include <weapon.h>

inherit STICK;

void create()
{
   set_name("���ְ�", ({"huanle bang", "bang"}));
   set_weight(10000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 5000);
     set("material", "steel");
     set("long", "һ�ѵ���ɫ����������ֻ��壬����Щ������\n");
     set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
     set("unwield_msg", "$N����һ������$n��غ�����\n");
   }
   init_stick(45);
   setup();
}
