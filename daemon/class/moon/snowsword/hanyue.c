//寒月吟花千层雪 BY Cigar 2002.01

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void qianxue_ok(object);

int perform(object me, object target)
{
        int damage,damagea;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「寒月吟花千层雪」？\n");
        if (!PFM_D->valid_family(me, "月宫"))
                return notify_fail("[寒月吟花千层雪]是月宫不传之密！\n");
        if(!me->is_fighting())
                return notify_fail("「寒月吟花千层雪」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("moondance", 1) < 120)
                return notify_fail("你的冷月凝香舞不够娴熟，使用这一招会有困难！\n");                
        if((int)me->query_skill("snowsword", 1) < 120)
                return notify_fail("你的风回雪舞剑法不够熟练，使用这一招会有困难！\n");
/*                
        if (me->query_skill_mapped("force")!="moonforce")
                return notify_fail("「寒月吟花千层雪」必须配合圆月心法才能使用。\n");
                
              
        if (me->query_skill_mapped("spells")!="moonshentong")
                return notify_fail("「寒月吟花千层雪」必须配合月宫仙法才能使用。\n");
*/
  
        if(me->query_temp("no_qianxue"))
                return notify_fail("你现在“寒月吟花千层雪”刚用毕，等会儿再用吧！\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        //damagea=random((int)me->query_skill("dodge")/2);
        damagea=random((int)me->query_skill("dodge"));
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
        {
                message_vision(HIW"\n$N凝望窗外寒绵小月，暖心未眠，心生诗意，低吟"+HIR"“寒月吟花千层雪”"+HIW"。\n"NOR,me,target);
                target->receive_damage("kee",damagea,me,"pfm");
                target->receive_wound("kee",damagea/2,me,"pfm");
                target->receive_damage("sen",damagea/3,me,"pfm");
                target->start_busy(2);
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIG"\n$N眠意已生，低吟句句缠绵，$n觉似情深，$N却感无味...\n"NOR,me,target);
        }
        message_vision(HIG"\n$N轻拭绢丝窗上雪花，看窗外寒梅，景映眼中，情自心生：“\n"NOR,me,target);
        message_vision(HIG"\n玉为花瓣雪为神，冰姿不怕雪侵，羞依绢丝窗下，醉心。\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIG"\n月明亭阁下，寒依疏影潇潇竹，池底影浮寒月，香闻流水，醉意。\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIG"\n窗前香遍酒阑人，酒腻花熏，酒不醉人人自醉。”\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        //damage=random((int)me->query_skill("sword")/2);
        damage=(int)me->query_skill("sword")+random((int)me->query_skill("parry"));
        if(random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
        {
                message_vision(HIC"\n小月、花香、酒醉，围绕在$N的周围，此情此景，早已让$n神魂颠倒....\n"NOR,me,target);
                target->receive_damage("kee",damage/2,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIY"\n$n冷冷一笑，此笑更添寒月余光。$n从怀中掏出一壶美酒，独自小酌。\n"NOR,me,target);
        }
        me->receive_damage("sen", 30);
        me->add("force", -100);
        me->set_temp("no_qianxue",1);
        call_out("qianxue_ok",2+random(2),me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        return 1;
}

void qianxue_ok(object me)
{
        if (!me) return;
        me->delete_temp("no_qianxue");
}

