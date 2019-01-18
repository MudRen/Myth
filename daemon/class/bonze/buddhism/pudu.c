#include <ansi.h>

inherit SSERVER;

string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BOLD,BLINK });
                        
        if( str && stringp(str) ) 
        {
                i = sizeof(color);
                while( i-- ) 
                {
                        str = replace_string(str, color[i], "");
                };
                return str;
         }
}


int cast(object me, object target)
{
        string msg,spells_skill,name;
        int ap,dp,ap1,dp1,pp,i,j,p;
        object weapon,*inv;

        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("spells") < 100 || (int)me->query_skill("buddhism",1) < 100)
                return notify_fail("�㻹ûѧ��[�նɴȺ�]������\n");

        if (me->query("env/invisibility")) 
                return notify_fail("�㲻�ַ�����ε㻯���ˣ�\n");
   
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("����㻯˭��\n");  
   
        if (!me->is_fighting() && (userp(target)))
                return notify_fail("���±����£��α�����֮��\n");
   
        if((int)me->query("mana") < 500 )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 200 )
                return notify_fail("���޷����о�����\n");

        me->add("mana", -200);
        me->receive_damage("sen",100);

        if (!PFM_D->valid_family(me, "�Ϻ�����ɽ")) 
                return notify_fail("��Ƿ��ŵ��ӣ��޷��㻯����\n");
        
        if ( me->query_skill("buddhism",1)< 100) 
                return notify_fail("�㻹û��ѧ��[�նɴȺ�]......\n");  
        spells_skill = target->query_skill_mapped("spells");
        ap = me->query_skill("spells") + me->query("cor");
        dp = target->query_skill("spells",1) + target->query("cps");
        ap1= me->query("cor");
        dp1= target->query("cps");
        if ((string)me->query("bonze/class") =="bonze" )
                pp = me->query_skill("buddhism",1)*2;
        weapon=target->query_temp("weapon");
        inv=all_inventory(me);
        i=sizeof(inv);
        me->delete_temp("condition/carrying_ok");
        j=0;
        while (i--)
        {  
                name = (string)(inv[i])->query("name");
                name = remove_ansi(name);
                if ( name == "��������" )
                        me->set_temp("condition/carrying_ok", 1);
            
        }      
        if ( !me->query_temp("condition/carrying_ok") 
           && ( userp(target)))
                pp = pp /2;
          
        if( !present(target, environment(me)) )
                return notify_fail("��λ��ǵ����˴������˰ɡ�\n");
            
        if( random(ap+dp) > dp)
        {
                if((string)me->query("family/master_id") == "guanyin pusa" && random(ap1)>random(dp1) ) 
                { 
                        msg = HIC"$N˫�ֺ�ʮ������΢�գ��������У�ȫ��£����һƬϼ��֮�С�����$N�����\n"NOR;          
                        switch (random(3))
                        {
                        case 0:
                        { 
                                msg += HIC"
    ������Χ�ƣ�����צ�ɲ�����˹������������ޱ߷���\n
    ���߼���Ы�������̻�Ȼ����˹�������Ѱ���Ի�ȥ��\n
    ���׹ĳ��磬���������꣬��˹�������Ӧʱ����ɢ......\n"NOR; break;}
      
                        case 1:
                        {
                                msg += HIC"
    �������������������
    �������������ܾ������......\n"NOR; break; }
                        
                        case 2:
                        { 
                                msg += HIC"
    ����������ǧ����������������գ�
    ���ǹ�����������һ�ĳ�����������������ʱ�����������Եý��ѡ�
    ���г��ǹ������������ߡ������𣬻����գ����������������ʡ�
    ��Ϊ��ˮ��Ư���������ţ�����ǳ��......\n"NOR; break; }
    
                        }
          
               
                if ( me->query_temp("condition/carrying_ok") )
                {                     
                        target->receive_damage("sen", pp*3,me,"cast");  
                        target->receive_wound("sen", pp*2,me,"cast");
                        target->add("mana",-200);
                        target->add("mana",-pp*2);
                        if (target->query("mana")<0) target->set("mana",0);
                }
         
                else 
                {
                        target->receive_damage("sen", pp*3/2,me,"cast");  
                        target->receive_wound("sen", pp,me,"cast");
                        target->add("mana",-100);
                        target->add("mana",-pp);
                        if (target->query("mana")<0) target->set("mana",0);
                }
                      
                msg += HIR"��֪������$n��Ȼ���������棬�૵�������ˣ�����......\n"NOR;
               
                if(objectp(weapon) && ( me->query_temp("condition/carrying_ok") || random(10)>7 ) )
                {
                        weapon->unequip();
                        weapon->move(environment(target));  
                        msg+="$n�������е�"+weapon->query("name")+"��̾������"+RANK_D->query_self(me)+"����ʼ�Ŵ����Ը�������ҷ�\n"NOR;
                }
                message_vision(msg,me,target);         
                COMBAT_D->report_sen_status(target);
        }
    
        else
        {
                msg = HIW"$N�����ȵ����������������سɷ𣡷������������سɷ𣡣��������������سɷ𣡣���\n"NOR;
                if (random(ap1+ap1)>random(dp1)) 
                {
                        msg += HIW"ֻ��$n�����㱣�����ҡҡ��׹��\n"NOR;
                        message_vision(msg,me,target);         
                        COMBAT_D->report_sen_status(target);
                        target->receive_damage("sen", pp,me,"cast");  
                        target->receive_wound("sen", pp/2,me,"cast");
                        target->add("mana",-100);
                        target->add("mana",-pp/2);
                        if (target->query("mana")<0) target->set("mana",0);
                }
   
                else {
                        if (spells_skill) {
                                msg += HIW"$nĬ��"+CHINESE_D->chinese(spells_skill)+HIW"��һ����ȣ������ڴ�װ��Ū��\n"NOR;                             
                                message_vision(msg,me,target);         
                 
                                if ( !me->query_temp("condition/carrying_ok") )
                                        me->start_busy(2+random(3));
                        } 
                }
        } 
   
        
        if( !target->is_fighting(me) )
        {
                if( living(target) )
                {
                        if( userp(target) ) target->fight_ob(me);
                        else
                        me->kill_ob(target);
                        target->kill_ob(me);
                }
        }
             
        return 1+random(4);
        }
   
        message_vision(HIR"$n������Ц�����������Ҳ����ˣ�Ҫ����"+RANK_D->query_rude(me)+"����߶Щʲô!\n"NOR,me,target);     
         
        return 3+random(4);     
}

