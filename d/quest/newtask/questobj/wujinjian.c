#include <weapon.h>

inherit SWORD;
void create()
{
        set_name("�ڽ�Ѫ��", ({ "wujin jian" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                       set("material", "iron");
 set("long", "���ֺ���֮�����������񽣣�����ұ��֮���ı����������ഫ��\n");
                       }
        init_sword(15);
        setup();
}
