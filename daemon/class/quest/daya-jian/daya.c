//����һ�£���֪��Ч����� by seng@2005-1-21
//�ο���moon��pfm tian;gumu��pfm jiujian;daya��pfm qijian;��combat.h

#include <ansi.h>
#include "/daemon/class/xuanyuan/daya-jian/eff_msg.h"; 
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    string dodskill,msg;
    int extra,i,j,tmp,strength,howlong,str,damage,targetforce;
    object weapon = me->query_temp("weapon");
    mapping action;
    extra = me->query_skill("daya-jian",1);
    j = me->query("opinion/mete");

    // howlong=me->query_skill("daya-jian")/(300+j*2);
    // mudring change arithmetic Feb/04/2005
    howlong = 1 + j/3;
    
    damage = extra + j*60;
    if(damage > 700) damage = 700;

    if(me->query("mark/dayagett") <1)
      return notify_fail("�۴��Ž�����ֻ�н���ſ���ʹ�ã�\n");
    if ( me->query_skill("sword",1) < 300) return notify_fail("��Ļ����������������죬������Ľ�����ô���ţ���\n");  
    if ( extra < 300) return notify_fail("��Ĵ��Ž������������죡\n");  
       
        if( (int)me->query("force") < 800 )      
                return notify_fail("�������������\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                 return notify_fail("�۴��Ž�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

		// mudring change 3 to 4 Feb/04/2005
		// and moved here....
       if( time()-(int)me->query_temp("daya_end") < 4 ) 
               return notify_fail(HIR "�����ö�Ͳ����ˣ�\n" NOR); 
               
               
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);


        me->add("force", -300);

         call_out("remove_ansi",howlong,me,str); 
         me->set("actions",action); 
         me->reset_action();


        if(!target->is_busy()) target->start_busy(2);


        message_vision(HIW  "\n\n$N�����е�"+ weapon->name() +RED"������ʣ���ָ���ܿ��ƵĶ���$n��ջ�����ȥ ��\n\n" NOR, me, target);



// modify by mudring Feb/04/2005
    message_combatd(HIY  "\n�����ŹŽ�����ʽ����$N����"+ weapon->name() +HIM"��Ϊ��ǧ��Ӱ��$n�����Ϸ��ȥ��" NOR, me, target);
    message_combatd(RED  "\n\n$N���ֳ�����"+ weapon->name() +RED"һ�٣���Ѫ˳��"+ weapon->name() +RED"�Ľ���εδ������������$N���¶���������Ĭ�"+HIW"�����������ɡ���" NOR, me, target);
    message_combatd(HIR  "\n$N�����е�"+ weapon->name() +HIM"������ȥ����Ȼ����˸�"+HIW"���{��רTһ��"+HIM"����$n�ĵ��Դ����ӷ��ɨ�䣡" NOR, me, target);
    target->receive_damage("kee", damage, me, "pfm"); 


	j=j+3;
	if (j > 8) j=8;
	for(i=0;i<j;i++) 
	{
        message_combatd(HIR  "\n$N�����е�"+ weapon->name() +HIM"������ȥ����Ȼ����˸�"+HIW"���{��רTһ��"+HIM"����$n�ĵ��Դ����ӷ��ɨ�䣡" NOR, me, target);
        if (i/3==0)
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        else
        if (i/3==1)
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_SUPER,msg);
        else
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg);       
   }

// end 

           targetforce = target->query("force");
           
// mudring change Feb/04/2004
           //if(targetforce < 0 ) targetforce = 0;
           //target->add("force",-targetforce/2);         

           target->add("force",-targetforce/2);
           if(targetforce < 0 ) targetforce = 0;
// end

         me->set_temp("daya_end",time()); 
         
        return 1;
}


int remove_ansi(object me,int extra) 
    {        
           object here; 
           extra = me->query_skill("daya-jian",1);  
           if(me->query_temp("apply/attack")) 
           me->add_temp("apply/attack",-extra); 
           if(me->query_temp("apply/damage")) 
           me->add_temp("apply/damage",-extra); 
           message_vision(HIW"$N�������б����ָ�ԭ����\n"NOR,me); 
           return 1; 
    } 
