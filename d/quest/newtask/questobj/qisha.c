#include <weapon.h>

inherit SWORD;
void create()
{
        set_name("��ɷ����", ({ "qisha tianluo" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                 set("material", "iron");
                set("long", "���ű�����ͨ���ںڣ������������˼����ƽ��������Բ�ƹ�����ȥ�Ʊ޷Ǳޣ��ƽ��ǽ���\n");}
        init_sword(15);
        setup();
}
