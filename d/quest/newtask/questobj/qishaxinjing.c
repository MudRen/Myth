#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("����ɱ�ľ���", ({ "qisha xinjing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "�书�ؼ�����ߺ�������ŷ�ɥ������ɱ�ơ���ɱָ��������ɱ������\n");
          }

    setup();
}
