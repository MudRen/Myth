//zhaoyaojian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "������" NOR, ({ "wawasword", "jian"}) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
                set("material", "iron");
                set("long", "һ������������˵����������֮Ч��\n");
                set("wield_msg","����һ����Х����������Ծ��$N�����С�\n");
                set("unwield_msg", "�������⽥��ɢȥ�������������Ծ�ؽ��ʡ�\n");
                                set("no_sell","�����������������޵ı������ٺ١������군�ˡ�\n");
                                set("no_drop","��Ҫ�ǰ����޵ı������ˣ����С��Ҳ��û�ˡ�\n");
                                set("no_give","���ǰɣ�����Ҳ�����ˣ������ǲ�Ҫ���ˡ�\n");
                }
        init_sword(120);
        setup();
}

