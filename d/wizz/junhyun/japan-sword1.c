//��һ���֡�����
//by junhyun@SK
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "��һ���֡�����" NOR, ({ "juyiwenzi zezong", "jian","sword" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
//              set("no_drop", "1");
                set("material", "iron");
                set("long", "̫�����г�78.48CM��������Ժʱ�ڱ�ǰ������������
����һ�����ɵĴ�����Ʒ����˵����Ϊ��׫�齣ʿ������˾���С�\n");
                set("wield_msg","$N��������һ����������һ�����Σ�һ�ɽ�������Ϯ��\n");
                set("unwield_msg", "$N��$n�ջ����䣬�����ĳ��˿�����\n");
                                set("no_sell",1);
                                set("no_get","�ú����ǲ�������ñ��˵Ķ�����Ŷ��\n");
                }
        init_sword(200);
        setup();
}

