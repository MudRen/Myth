#include <weapon.h>
#include <ansi.h> 
inherit SWORD;

void create()
{
        set_name(HIC"���鳤��"NOR, ({ "spirit sword", "sword" })); 
        set("long", "����ı�����а����ž���֮����������\n");
        set("no_get",1);
        set("no_give",1);
        set("no_steal",1);
        set("no_sell",1);
        set("no_put",1);
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "iron");
                set("wield_msg", HIC"$N���ֽ�ӡ����ĿĬ�����һ���â��$N����������$n"NOR+HIC"�������Ρ�\n"NOR);
                set("unwield_msg", "$n"+HIC"��$N����һԾ���𣬻�ΪһƬ�����Ĺ�â��\n"NOR); 
        }
        init_sword(120);
        setup();
}

void owner_is_killed()
{
        write(HIY"ֻ�����һ������ʲô���������ˡ�\n"NOR);
       destruct(this_object());
}
/*
int query_autoload()
{
        write(HIG"һ����������࣬�·������ʲô���\n"NOR);
       return 1;
}
*/ 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int may, dam;
        may = random(5);
        if(may >3)
        { 
        dam = random(10)+10;
        victim->receive_wound("kee",dam);
        return HIC "���鳤������һ�����⣬���û�����$n��\n" NOR;
        }
}


