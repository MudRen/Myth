#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�������񹦱�����", ({ "sanguang baoji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "��ɽ�ɱ�����ѧ�ؼ������ϡ������ᡣ�ϲ�Ϊ���⽣��ƪ���²�Ϊ����ȭ��ƪ���Ʒ�ƪ��\n");
          }

    setup();
}
