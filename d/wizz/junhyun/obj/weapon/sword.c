//��ǹ�����㣨junhyunר�ã�
//by junhyun@SK
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"ʥ��������"NOR, ({ "sheng jian","jian","sword" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200000);
                set("no_sell", "���ֺ���������ɲ���������������!\n");
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("material", "wood");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("long", HIC"ħ���˽ܼ�֮һ��ʥ��������\n"NOR);
                set("wield_msg", HIY"$N����һ�ӣ������Զ���һ����������ʥ����\n");
        //      set("unwield_msg", "$N����һ������$n��غ�����\n");
        }
   init_sword(200);
        setup();
}

