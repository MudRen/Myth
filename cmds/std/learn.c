// modified by kuku 2003.5.9

#include <ansi.h> 
#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "˵������̫�����ˣ�����ô�ҵ���\n",
        "�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
        "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string skill, teacher, master;
        object ob;
        int master_skill, my_skill, sen_cost;
        int temp,upper, sen1;
        int amount, qskill, qlearned, i;

        if(!arg) return notify_fail
                    ("ָ���ʽ��learn <����> from <ĳ��> \n");
/*
        if(sscanf(arg, "%s for %d", arg, time)!=2 ) 
            time=1;
        
        if(time<1) time=1;
        if(time>50) time=50;
*/
        if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
            return notify_fail
                    ("ָ���ʽ��learn <����> from <ĳ��> \n");

        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");

        if(me->is_busy())
            return notify_fail("����æ���ء�\n");

        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("��Ҫ��˭��̣�\n");

        if( !living(ob) )
                return notify_fail("�ţ���������Ȱ�" + ob->name() + "Ū����˵��\n");

        if( !me->is_apprentice_of(ob) && ob->query("id") != me->query("couple/id") && !(ob->recognize_apprentice(me)) ) {
                notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
                
        if( (string)me->query("family/family_name") != (string)ob->query("family/family_name")
                ||(int)ob->query("family/privs") != -1 ) {
                        if( !(ob->recognize_apprentice(me)) ) return 0;
                } 
                else return 0; // mon add this return 0. 5/6/98
        }

        if( ob->is_fighting())
                return notify_fail("���ʦ����ʱû��ָ�����书��\n");

        if( !master_skill = ob->query_skill(skill, 1) )
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");

        notify_fail(ob->name() + "��Ը���������ܡ�\n");
        if( ob->prevent_learn(me, skill) )
                return 0;

        my_skill = me->query_skill(skill, 1);

/*
        if(me->query("level")< 50 && my_skill >= 200) 
                return notify_fail("����Ŀǰ�ĵȼ���û�а취ѧϰ����ܡ�\n");  
        if(me->query("level")< 100 && my_skill >= 300) 
                return notify_fail("����Ŀǰ�ĵȼ���û�а취ѧϰ����ܡ�\n");  
        if(me->query("level")< 150 && my_skill >= 450) 
                return notify_fail("����Ŀǰ�ĵȼ���û�а취ѧϰ����ܡ�\n");  
        if(me->query("level")< 200 && my_skill >= 600) 
                return notify_fail("����Ŀǰ�ĵȼ���û�а취ѧϰ����ܡ�\n");  
        if(me->query("level")< 250 && my_skill >= 800) 
                return notify_fail("����Ŀǰ�ĵȼ���û�а취ѧϰ����ܡ�\n");  
*/
        
        if( !SKILL_D(skill)->valid_learn(me) ) return 0;

        sen_cost = 300 / (int)me->query_int();

        if( !my_skill ) {
                sen_cost *= 2;
//              me->set_skill(skill,0);
        }
        
        upper= (int)me->query("potential")-(int)me->query("learned_points");
//      if(time>upper) time=upper;

        if(upper<=0)
                return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");

        if(!my_skill) {
        qskill=1; temp = 2; amount=0;
        } else {
            qskill=me->query_skills()[skill]+1;
            temp = qskill * qskill;
//            qlearned=me->query_learned()[skill];
//            amount = qlearned;
        }

        // for those level higher than master's
/*        if( amount > qskill )  {
           for(i=0; i<time; i++)
               amount += random(me->query_int())+1;
        }
        else {
           for(i=0; i<time; i++)   {
              amount += random(me->query_int())+1;
              if( amount > qskill )  {i++;break;}
           }        
        }
       
          amount -= qlearned;
          time = i;
*/       
        sen_cost = random(100);

        printf("����%s����йء�%s�������ʡ�\n", ob->name(),
                to_chinese(skill));

        if( ob->query("env/no_teach") )
                return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");

        // can't learn from another player if oneself
        // don't have the skill.
        if(userp(ob) && (int)my_skill<1) {
            return notify_fail("��������ôҲŪ�����ס�\n");
        }

        // can't learn above 100 level from a player.
        // mon 3/7/98
        if(userp(ob) && my_skill>=100)
          return notify_fail("����"+
            ob->name()+"�Ѿ�����ָ�����һ������ˡ�\n");

        tell_object(ob, sprintf("%s��������йء�%s�������⡣\n",
                me->name(), to_chinese(skill)));

    sen1=(int)ob->query("sen");
    if(userp(ob) || sen1<50)
        if(sen1 > sen_cost + 1 ) {
                if( userp(ob) ) ob->receive_damage("sen", sen_cost+1);
        } else {
                write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲô��\n");
                tell_object(ob, "������̫���ˣ�û�а취��" + me->name() + "��\n");
                return 1;
        }
                
        if( (int)me->query("sen") > sen_cost ) {
                if( (string)SKILL_D(skill)->type()=="martial"
                &&      my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
                        printf("Ҳ����ʵս���鲻�������%s�Ļش������޷���ᡣ\n", ob->name() );
                }
                else if( (string)SKILL_D(skill)->type()=="magic"
                &&      my_skill * my_skill * my_skill / 10 > (int)me->query("daoxing") ) {
                           printf("Ҳ���ǵ��в��������%s�Ļش������޷���ᡣ\n", ob->name() );
                }
               
                else {                             
                     //added by mon. 7/24/97
                     //to learn beyond NPC master's skill with an added cost.  
                     //modified by kuku  2003.5.9                  
                        if( my_skill < master_skill ) {
                                if(!my_skill) 
                                        qskill=1;
                                else
                                        qskill=me->query_skills()[skill]+1;
                        temp = qskill * qskill * 11/10;
                        temp = temp/25; 
                                    if (upper < temp){
                printf("���Ǳ�ܲ���,������һ��"+to_chinese(skill)+"����Ҫ"+temp+"��Ǳ�ܡ�\n");
                                        return 1;
                                }             
                                    me->add("learned_points", temp);
                                printf(HIW+"��ϲ�����"+to_chinese(skill)+"�ﵽ��"+qskill+"����\n"); 
                                me->set_skill(skill,qskill);                         
                        } 
                        else {
                                    qskill=me->query_skills()[skill]+1;
                                temp = qskill * qskill * 4;
                        temp = temp/25; 
                                if (upper < temp){
                printf("���Ǳ�ܲ���,������һ��"+to_chinese(skill)+"����Ҫ"+temp+"��Ǳ�ܡ�\n");
                                        return 1;
                                }             
                                me->add("learned_points", temp);                                            
                                message_vision("$N��$n˵����"+
                                "��ġ�"+to_chinese(skill)+
                                "���Ѿ�����Ϊʦ�ˣ�����һ���д��д�ɣ�"
                                +"\n",ob,me);
                                printf(HIW+"��ϲ�����"+to_chinese(skill)+"�ﵽ��"+qskill+"����\n"); 
//                        me->improve_skill(skill, amount,
//                          (qlearned>4*qskill && !userp(ob)) ?0:1);
                          //can't learn beyond a player master's level.
                                me->set_skill(skill,qskill);                        
                        }                     
                }
        } 
        else {
//              sen_cost = me->query("sen");
//              if(sen_cost<0) sen_cost=0;
                write("�����̫���ˣ����ʲôҲû��ѧ����\n");
                me->start_busy(1);
                return 1;
        }

        me->receive_damage("sen", sen_cost );
//      me->start_busy(1);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : learn|xue <����> from <ĳ��>
 
���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ���������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱��һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����

ͨ����һ���˸�ѧ��һ���¼����ǲ�����ʲô��������ģ����Ǿ���ʵ���ϵ�Ӧ����
�������⣬��Щ�������ѧϰһ���¼��ܵĹ����Ǻ���Ҫ�ģ������Ǹ�����Ϊ������
�ܻ����Ļ������ܣ�����Ҫ���ɡ��������⩤������⡹�Ĺ��̲��ܵõ��Ϻõ�Ч��
������ǽ����ַ�������Ĺ����á�Ǳ�ܡ��Ĺ����ʾ��һ�����ܹ��Լ�����ĳЩ��
�⣬��ʾ��(��)�н�����������Ǳ�ܣ��������������Ǳ��ʱ�Ϳ����������ָ��
������������̣�����ý�����
(PS. Ǳ�ܻ�������������Ķ��壬����ֻ������֮һ )

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�

�������֪�����ܴӶԷ�ѧ��ʲô���ܣ�����Է������ʦ���������� skills ָ��
ֱ�Ӳ鿴������������ʦ������ôͨ��������������ʾ����ֻ���Լ���취��

�������ָ�� : practice��study
HELP
        );
        return 1;
}
