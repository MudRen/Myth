#include <weapon.h>

inherit SWORD;
void create()
{
        set_name("�������׶���׷���", ({ "zhuihun ci" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                       set("material", "iron");
 set("long", "ϵ��ǧ�����㱳����������Ч��ҩ��ĥ�����ɵ����ű�����\n");
                       }
        setup();
}
