
#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

#include <magic_power.h>

string get_name(){return "������";}//��������
string get_help()                  //����˵��,�Ժ�ֱ��help,�����޸�
{
        return "�����������ʩչ����֮�𺣣������������ÿ����ɫ��������ͬ\n
,�����ǹ̶��ġ��˷����������ã���Ҫһ���ķ�����ħ���㣡\n 
����Ч���ɸ��������У�ħ��ʦ �ս��� ������ ���ڵ���ʹ�� ���� Ұ���ˡ�";

}

int do_cast(object me,object target)
{
        object *ob;
        string helltype,msg;
        int damage,i;
        
        
        if(!me->is_fight())
        {
                tell_object(me,"��û��ս���У�\n");
                return 1;
        }
        
        if(me->query("mana")<300)
        {
                tell_object(me,"��ķ���̫���ˣ������ò����������!\n");
                return 1;
        }
        
        if(me->is_busy())
        {
                tell_object(me,"����æ����!\n");
                return 1;
        }
        
        if(me->query("magic_pointed")<50)
        {
                tell_object(me,"���ħ����̫���ˣ������ò����������!\n");
                return 1;
        }
        
        helltype=me->query("hell_type");
        if(!helltype) helltype="Ұ����";
        if(!userp(me)) return 1;
        me->add("mana",-2* (120-magic_power[helltype]));
        me->add("magic_pointed",-(120-magic_power[helltype])/2);
        msg=HIC "\n"+me->query("name")+"" NOR;
        msg += CYN "ʹ��"+HIR+"<����֮��>"+CYN+"��˫�ֻӳ�һ����Ļ������ķ���ȥ��\n\n" NOR;
        tell_room(environment(me),msg);
        damage=100-magic_power[helltype];
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) 
           {
                if(ob[i]==me ) continue;                                                   
                if(!living(ob[i]))  continue;
                if(random((100-magic_power[helltype])*6) > (50+ob[i]->query("level"))/2 )
                {
                        ob[i]->receive_damage("kee", damage*6+random(damage),me);
                        ob[i]->receive_wound("kee", damage*2+random(damage),me);
                        message_vision(HIC "$n��$N�Ļ��յĻ������ˣ���ֱ�У���\n" NOR,me,ob[i]);
                        COMBAT_D->report_status(ob[i]);             
                
                }
                else
                {
                         message_vision(CYN "$n��$N�Ļ�â�ֵĺں����Ǳ���$n��ʱ��æ�������������ϵĻ�\n" NOR,me,ob[i]);
                
                }
                if(!userp(ob[i])) ob[i]->kill_ob(me);
            }     
            
        me->start_busy(random(3)+1);                   
        return 1;
}


