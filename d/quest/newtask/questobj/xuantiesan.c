#include <weapon.h>

inherit SWORD;
void create()
{
        set_name("������ɡ", ({ "xuantie san" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                       set("material", "iron");
 set("long", "���ű��������г������й��׳�����ü���ֱ����Ĺ��ܣ��ſ��������Եֵ�������\n");
                       }
        setup();
}
