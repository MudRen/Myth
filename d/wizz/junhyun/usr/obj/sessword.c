//��֮Ȩ��
//by junhyun@SK
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "��֮Ȩ��" NOR, ({ "sessword", "jian"}) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
                set("material", "iron");
                set("long", "�����Ȩ�ȣ��ƹ������һ�С�\n");
                set("wield_msg","$N�������է�֣���֮Ȩ���������֡�\n");
                set("unwield_msg", "��⽥��ɢȥ��$n��ʧ����Ӱ���١�\n");
                                set("no_sell","�����������������뱦����Ȩ�ȣ��ٺ١������군�ˡ�\n");
                                set("no_drop","��Ҫ�ǰ����뱦����Ȩ�����ˣ����С��Ҳ��û�ˡ�\n");
                                set("no_give","���ǰɣ�����Ҳ�����ˣ������ǲ�Ҫ���ˡ�\n");
                }
        init_sword(120);
        setup();
}

