//by repoo

#include <ansi.h>
#include <weapon.h>

inherit SPEAR;
inherit F_UNIQUE;

void create()
{
  set_name(HIR"��¯"+HIW"ǹ"NOR, ({ HIR"tilu qiang"NOR, "qiang", "spear" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "bone");
              set("long", "���ǹ����������͵���������ת���ġ�\n");
                set("wield_msg", "һ���׹�������$N�����Ѷ��˰�$n��\n");
        }
         init_spear(150);
        setup();
}
void init()
{
        check_owner();
}

int ji_ob(object victim)
{
        object fabao=this_object();
        object me=this_player();
        object where=environment(me);

        int my_spi;

        int vic_enchant, vic_dx, vic_mana;
        int damage;

        fabao->set("spi", 0);
         fabao->add("spi", 6000);
        if( me->is_busy() )
  return notify_fail("����æ���أ��޷�����"+HIR"��¯"+HIW"ǹ��\n"NOR);
        if( !victim )
                return notify_fail("��������˲������\n");
        if( where->query("no_magic") )
        return notify_fail("���ﲻ�ܼ�"+HIR"��¯"+HIW"ǹ��\n"NOR);
        if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в��ܼ�����\n");
        if( (int)me->query("mana") < 800 )
 return notify_fail("��ķ������ܿ���"+HIR"��¯"+HIW"ǹ��\n"NOR);

message_vision(YEL"\n$N���һ����ȥ!����ֻ��$n"+YEL"��������һ�»���һ�������ɵ���ա�\n"NOR, me, fabao);

message_vision(YEL"���Ǽ���ɫһ�䣡$n"+YEL"��Х����"+HIW"$N"+YEL"ӭ����£�\n"NOR, victim, fabao);
        if( !victim->is_fighting(me) ) 
        {
                if( living(victim) ) 
                {
                        if( userp(victim) ) 
                                victim->fight_ob(me);
                        else
                                victim->kill_ob(me);
                }
                me->kill_ob(victim);
        }

        me->add("mana", -500);
        me->receive_damage("sen", 100);
        me->start_busy(1+random(3));

        my_spi = query("spi");
        fabao->set("spi", my_spi*3/2);
        //������ɹ�
        vic_mana = (int)victim->query("mana");
        vic_dx = (int)victim->query("daoxing");
        vic_enchant = (int)victim->query("mana_factor");

        if( random(vic_dx/1000) > my_spi ) 
        {
message_vision(HIY"\n���$N���μ����������$n"+HIY"�Ĺ��ơ�\n"NOR, victim, fabao);
        }
        else
                if( random(vic_mana) > my_spi )
                {
message_vision(WHT"\n$N��һָ���һ������������ֻ��$n"+WHT"����һ���������ɵ���"+HIR"$N"+HIW"���С�\n"NOR, victim, fabao);
                        fabao->move(victim);
                }
                else
                {
                        damage = 0;
                        damage = 100 + my_spi/2 - random(vic_mana/10) - vic_enchant*2;
                        if( damage < 0 ) damage = 0;
                     if( damage > 3000 ) damage = 3000; 

                        if( damage > 0 )
                        {
message_vision(HIY"\n���$N"+HIY"�������������׹�����֮��$n"+HIY"�Ѿ�����"+HIW"$N"+HIY"������,\n"+HIY"        ����һ�ᣬ��Ѫ���������\n\n"+"        $n"+HIW"ͨ�����ʵ��,��������ǿ��.\n"NOR, victim, fabao,victim);
                                victim->receive_damage("kee", damage);
                                victim->receive_wound("kee", damage/2);
                                fabao->add("spi",100);
                                COMBAT_D->report_status(victim);
                        }
                }
        return 1;
}

int ji (string target)
{
        object fabao = this_object ();
        object me = this_player();
        string name=fabao->query("name");
        object victim;

        if (!target)
                return notify_fail("�����˭��"+name+"��\n");
        victim=present(target,environment(me));
        return fabao->ji_ob(victim);
}
