//Cracked by Roath
#include <ansi.h>

inherit NPC;
int types;
string *names = ({ "��ѻ", "��ӥ", "��ȸ","������","���","������"});
string *ids = ({ "wu ya","lao ying","kong que","dapeng niao","feng huang","busi niao"});
string *msg_in=({HIB"����д���һ�����ӵ�������һֻ��ѻ���˹�����",
                            HIC"ֻ������л���һ����ɫ���磬һֻأӥ���˶�����",
                           HIM"��ֻ������ǰһ������ͷף�һֻ�����Ŀ�ȸ�����������ǰ��",
                           HIY"��̼�һ���ɳ��ʯ�������޹⣬һֻ������ʮ�ɵĴ�������������",
                           HIG" ͻȻ�����ܰ���������һֻ��˰�Ȼվ���������ǰ��",
                            HIR"��������Ļ���ȼ��������������ӻ����з��˳���......"
                         });

string *msg_out=({HIB"��ѻ�ս���ͣ�һ����������ˡ�",
                            HIC"��ӥ����Զ����ֻ���ӣ�˫��һ��ֱ��������ȥ��",
                            HIM"��ȸ�������˦��˦β�ͣ�һ����ҡ�������ˡ�",
                            HIY"�����������˼��³�򣬸߽�һ������ȥҲ�������ټ������ˡ�",
                           HIG"������ĵش��˸���Ƿ�����ĵس����ܿ��˿������ĵط����ˡ�",
                           HIR"�����˸еĻ���ȼ���������������������з�����......"
                          });
string *combat_msg=({"��ѻ���ɵؽ��˼���������$N�ķ����",
                                      "��ӥ�ɵ���գ�ವ�һ��Ͷ��һ�����ը����������$N��ͷ�ϡ�",
                                      "��ȸ��β����$N��ǰ������ȥ������$N�ۻ����ҡ�",
                                      "���������˫�ᣬ����$N�����ȷ磬����$N���۾�����������",
                                      "��˳嵽$N����ǰ�������ؿ���$N,$N�Բ��λ࣬����һ�����١�"
                                      "���������һ����棬����$N�ճɿ������"
                                 });



void create()
{
        set_name("����", ({"fighter"}));
        set("title", "ѩɽ����");
        set("gender", "����" );
        set("class", "yaomo");
        set("age", 20);

        set("chat_chance_combat", 5);
        set("chat_msg_combat", ({
          (: saysth :),
           }) );

        setup();
}
void set_level(int lvl) {

        int kee=lvl*1000+500;
    
       if (lvl==5) kee=2000;
       set("level",lvl); 
       set_name(names[lvl], ({ids[lvl],"fighter"}));
        set("long", "һֻ�õ������"+names[lvl]+"����˵�Ǵ����������µĵ����ɽ���\n");
        set("str", 30);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 50);
        set("max_kee",kee );
        set("max_sen", kee);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 10);
        set("mana", 1000);
        set("max_mana", 1000);
        set("mana_factor", 50);
        set_skill("spells", 50+lvl*40);
        set_skill("force", 50+lvl*40);
        set_skill("unarmed", 50+lvl*40);
        set_skill("dodge", 100+lvl*40);
        set_skill("parry", 50+lvl*40);
        set("combat_exp", 100000+lvl*200000);
        set("daoxing", 100000+lvl*200000);
        set("limbs", ({ "ͷ��", "����", "��צ", "β��", "��Ƥ", "��צ","���","����"}) );

        setup();

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        string msg=msg_out[query("level")];
        messege_vision(msg+"\n"NOR,this_object());
        destruct(this_object());
}

void invocation(object who)
{       int i,lvl;
        object *enemy;
        string msg=msg_in[query("level")];
        object me=this_object();

        lvl=(who->query_skill("dengxian-dafa",1)-40)/40;
        if (lvl==5) lvl=4;
        if (lvl>5) lvl=5;

        message_vision(msg, me );
        set_level(lvl);                
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else {
                            enemy[i]->kill_ob(this_object());
                            enemy[i]->kill_ob(who);
                        }
                }
        }
        set_leader(who);
        call_out("check_leader", 5, who);
}

int check_leader(object who)
{
        if( !present(who, environment(this_object()))){
                call_out("leave", 1);
        } else {
                call_out("check_leader", 5, who);
        }
        return 1;
}

void die() {
       if (query("level")==5) {
            message_vision(HIG"$N��������������������ģ�����������\n"NOR,this_object());
            set("kee",2000);
            set("sen",2000);
            set("eff_kee",2000);
            set("eff_sen",2000);
              return;
        } else return :die();
}   
void unconcious() {
       if (query("level")==5) {
            message_vision(HIG"$N��������������������ģ�����������\n"NOR,this_object());
            set("kee",2000);
            set("sen",2000);
            set("eff_kee",2000);
            set("eff_sen",2000);
            return;
        } else return :unconcious();
}





