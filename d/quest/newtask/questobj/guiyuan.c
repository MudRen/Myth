#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("����Ԫ�ؼ���", ({ "guiyuan miji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ������Ԫ�����������������Ѱ��ԡѪ�ಫ����ѧ���飬Ϊ������˺���������������\n");
          }

    setup();
}
