#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�����¼��", ({ "wuguilu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "�伮���ɾ��˺��ж��ɣ���Ҫ������������˹����ʿ��˹����ɣ���ձ������Ŵ󿪣��й��Ĵ�����С�\n");
          }

    setup();
}
