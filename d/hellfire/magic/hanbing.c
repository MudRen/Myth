// created 2002 by stey
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit H_MAGIC_ITEM;

void create()
{
  set_name(HIW "ħ����" NOR, ({ "scroll"}));
  set_weight(100);
          if( clonep() ) 
                 set_default_object(__FILE__); 
         else { 
                  set("long",HIY"����һ�������ر�ħ����ħ���䡣\n"NOR); 
                 set("unit", "��"); 
                 set("base_unit", "��"); 
                 set("base_weight", 5); 
                 set("value", 3); 
         } 
  set("sp_name",HIC"����");//ע���������sp_name sp_id sp_long����
  set("sp_id","ice scroll");  
  set("sp_long","ˮϵ��ͨħ��,�ٻ�����������ħ���䡣\n");
  set("magic_type","water"); //ħ��ϵ
  set_amount(1);
  setup();
  
}


int cast(object me, object target) //ħ��������lpc����
{
        int success_adj, damage_adj; 
 

        success_adj = 110; 
        damage_adj = 100;//stey�����80-100�ȽϺ��ʣ�130���Һ�����
 
        if( !target ) target = offensive_target(me); 
 
        if( !target 
        ||      !target->is_character() 
        ||      target->is_corpse() 
        ||      target==me) 
                return notify_fail("��Ҫ�ú�����˭��\n"); 
 
        if(me->query("hell_type")!="������"&& me->query("hell_type")!="ħ��ʦ" && me->query("hell_type")!="�ս���") 
                return notify_fail( me->query("hell_type")+"����ʹ��ˮϵħ����\n"); 
 
        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") ) 
                return notify_fail("��ķ���������\n"); 
 
        if((int)me->query("sen") < 20 ) 
                return notify_fail("���޷����о������������Լ��ˣ�\n"); 
          if(me->query("hell_type")=="ħ��ʦ")
                        damage_adj = damage_adj +35;
          if(me->query("hell_type")=="�ս���")
                        damage_adj = damage_adj +10;
        me->add("mana", -25-2*(int)me->query("mana_factor")); 
        me->receive_damage("sen", 10); 
 
        if( random(me->query("max_mana")) < 50 ) { 
                write("����û��Ӧ������һ�ΰɣ�\n"); 
                return 1; 
        } 
 
        //HELLMAGIC_D->attacking_cast( 
         SPELL_D->attacking_cast( 
                me,  
                        //attacker  
                target,  
                        //target 
                success_adj,     
                        //success adjustment 
                damage_adj,      
                        //damage adjustment 
                "both",                  
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both" 
                HIC "$N�������˼������ģ�������������Ắ����\nৣ���һ����$n��ͷ���£�\n" NOR, 
                        //initial message 
                HIC "���������ţ����û��$n������\n" NOR,  
                        //success message 
                HIC "����$n��ǧ��һ��֮�ʻ��⺮��������\n" NOR,  
                        //fail message 
                HIC "���Ǻ�����$n�Է���һ���������ֵ���$N��ȫ��\n" NOR,  
                        //backfire initial message 
                HIC "�����������������ţ����û��$n������\n" NOR 
                        //backfire hit message. note here $N and $n!!! 
        ); 
 
        me->start_busy(1+random(2));      
  

}



