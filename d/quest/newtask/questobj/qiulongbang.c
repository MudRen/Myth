#include <weapon.h>
#include <ansi.h>
inherit STICK;
void create()
{
        set_name(HIW"˫����˿�����"NOR, ({ "qiulong bang" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                 set("material", "iron");
 set("long", "һ��������Ӳ�����α�����Ϊ����˫���е��϶�������������֡�\n");
             }
        init_stick(15);
        setup();
}
