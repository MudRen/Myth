#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "����һЦ" NOR, ({ "sword" }) );
    set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
//              set("no_drop", "1");
                set("material", "iron");
                set("long", "�������ܲܰ�ķ��������ô˽�նɱ��������ħ��\n");
                set("wield_msg","$N΢΢һЦ��$n����$N���У���Χ֮�˶���Ľ���ѡ�\n");
                set("unwield_msg", "$N��$n������䣬�����Ц����Ȼ������\n");
                                set("no_sell",1);
                                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
                }
        init_sword(150);
        setup();
}
