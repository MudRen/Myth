#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("������������", ({ "lianhua baojian" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "���ָ��������������书�ķ����������¶����������������˷Ź�������˹�������ȣ����ݹ㷺��\n");
          }

    setup();
}
