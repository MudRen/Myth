#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name("��������", ({ "miantie fuchen" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                       set("material", "iron");
 set("long", "�置�춾�ӹ����ʹ�õ����ƶ��Ƶı�����\n");
                  }
           setup();
}
