// jiuyou.c
// created by kuku@sjsh  2002/11

#include <ansi.h>
inherit NPC;
int time_period(int timep, object me);
string sysmsg;
object owner() {return query("owner");}
int give_quest();
int do_cancel();

void create()
{
        set_name(HIB "��������" NOR, ({ "jiuyou", "jiu you", "yiren" }) );
        set("gender", "����");
        set("age", 99);
        set("long",
            "��������������ף��׷�ͯ�ա�����һ���ӽ���֮���ˣ���������
���������꣬���Ǻڰ������ϵ���һ�������������޲��������֡�\n");
        set("attitude", "peaceful");
        set("str", 26000);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("per", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
            "�������������̳��˼��ڣ�������\n",
        }) );
        set("force", 40000);
        set("max_force", 80000);
        set("force_factor", 1000);
        set("combat_exp", 100000000);
        set_skill("unarmed", 120);
        set_skill("force", 100);
        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);
        set("title", HIC"����Ұ��"NOR);
        set("inquiry", ([ 
                "quest" : (: give_quest :),
                "cancel" : (: do_cancel :),
        ]) );
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/cloth/buxie")->wear();
}

int accept_fight(object me)
{
        command("say �����ɹ󣡲�Ҫ��Ѱ��·��");
        return 0;
}

int accept_object(object who, object ob)
{
        int  exp, pot, score,i;
        string nm,id;
        nm=who->query("task/name");
        id=who->query("task/id");
        if(ob->query("name")!=nm||ob->query("id")!=id)
        {
            tell_object(who,"��������˵�����ⲻ������Ҫ�ġ�\n");
            return 0;
        }
        if( ob->is_character())
        {
            tell_object(who,"��������˵�����ⲻ������Ҫ�ġ�\n");
            return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
            tell_object(who,"��������˵�������ϧ����û����ָ����ʱ������ɣ�\n");
            return 1;
        }
        else
        {
            tell_object(who,"��������˵������ϲ�㣡���������һ������\n");
            score = (int) who->query_temp("quest_number");
        exp =1000+random(3000)+400*score;
        pot = exp / 8 ;
        if (random(2)==1){ 
            who->add("combat_exp",exp);
            who->add("potential",pot);
            who->add("balance",20000);
            tell_object(who,HIW"��õ���"+exp+"����ѧ"+pot+"��Ǳ�ܵĽ�������Ĵ�������˶����ƽ�\n" NOR);
            message("channel:rumor",HIM"��"+HIW"ҥ�Դ�˵"+HIM"��"+who->name()+"��"+this_object()->query("name")+"�ҵ��ˡ�"+ob->query("name")+"�����õ���"+exp+"����ѧ��"+pot+"��Ǳ�ܡ�\n"NOR,users());}
           else {
            who->add("daoxing",exp);
            who->add("potential",pot);
            who->add("balance",20000);
            tell_object(who,HIW"��õ���"+COMBAT_D->chinese_daoxing(exp)+"���к�"+pot+"��Ǳ�ܵĽ�������Ĵ�������˶����ƽ�\n" NOR);
message("channel:rumor",HIM"��"+HIW"ҥ�Դ�˵"+HIM"��"+who->name()+"��"+this_object()->query("name")+"�ҵ��ˡ�"+ob->query("name")+"�����õ���"+COMBAT_D->chinese_daoxing(exp)+"���к�"+pot+"��Ǳ�ܡ�\n"NOR,users());
         }
       if (score == 10){
       who->delete_temp("quest_number");
        i = 300000+random(500000);
        who->add("balance",i);
        tell_object(who,HIG"�����У���õ���"+chinese_number(i/10000)+"���ƽ�ĸ��ӽ�����\n"NOR);  } 
        who->set_temp("task/done",1);
        who->delete("task/name");
        who->delete("task/id");
        who->delete("quest_ask");
        who->delete("task_give");
       return 1; }
        return 1;
}

int give_quest()
{
        object me,person,newob;
        int j, t, timep;
        string where;
        mixed* file,local;
        me = this_player();
        if((int)me->query("combat_exp") >= 50000000)
        {
            write("���������Ѿ���������κ������ˣ�\n");
            return 1;
        }
        if(!userp(me)){
                write("���ˮ���㣿û�ţ���\n");
                return 1;
        }
        if((int) me->is_ghost())
        {
            write("��겻��Ҫ����\n");
            return 1;
        }
        if(me->query("task/name")&&me->query("task/id"))
        {
          if( ((int) me->query("task_time")) >  time() ) 
          {
            command("say �������ҵĶ����أ�\n");
            return 1; 
          }
          else
               me->set("kee", me->query("kee")/2+1);
               me->delete_temp("quest_number");
    
        if(!me->query_temp("task/done") || !me->query_temp("task/cancel")){
            command("say �����һ������û����ء�\n");
            return 1; }
        }
        person = new(__DIR__"questnpc");
        where=person->invocation(me);
        person->set("owner",me);
        file = get_dir("/d/quest/newtask/questobj"+"/*.c",-1);
        if( !sizeof(file) )  return 0;
        j = random(sizeof(file));
        if( file[j][1] > 0 ) { 
            newob=load_object("/d/quest/newtask/questobj"+"/"+file[j][0]);
            }
        timep = 600;   // each quest give 10 mins.
        timep = random(timep/2)+timep/2;
        time_period(timep, me);
        tell_object(me,where+"���㣬����Ҫ�ء�"+newob->query("name")+"����\n" NOR);
        sysmsg +="�һء�"+newob->query("name")+"����";
        me->set("task_time", (int) time()+(int) timep);
        me->set("task/name", newob->query("name"));
        me->set("task/id", newob->query("id"));
        me->set_temp("task/ob",person);
        me->delete_temp("task/done");
        me->delete_temp("task/cancel");
        if((int)me->query_temp("quest_number") < 20)
        me->add_temp("quest_number",1);
        CHANNEL_D->do_channel(this_object(), "job", sprintf("%s(%s)��%s",
        me->query("name"),me->query("id"),sysmsg));
        return 1;
}

int do_cancel()
{
             object me = this_player();
             object person;
        if (!me->query("task/name")||!me->query("task/id"))
                  {tell_object(me,"��û����������\n"); return 1;}
            me->delete_temp("quest_number");
            me->delete("task/name");
            me->delete("task/id");
            me->delete("quest_ask");
        me->delete("task_give");
        me->set_temp("task/cancel",1);
        me->command("say ���������ӿ�������Ϊ����\n");
        command("say �ðɣ���������Ϣ��Ϣ�ɡ�\n");
            person=me->query_temp("task/ob");
             if (living(person))
             {
             destruct(person);
            }
             return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "��";
        else time = "";
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"˵��������" + time + "�ڣ�");
        sysmsg = "��" + time + "��";
        return 1;
}

void die()
{
        if (environment())
        message("sound", "�������ˡ�������һ��̾�˿�����\n", environment());

        set("eff_kee", 10000);
        set("eff_gin", 10000);
        set("eff_sen", 10000);
        set("kee", 10000);
        set("gin", 10000);
        set("sen", 10000);
        set("force", 10000);
        set("mana", 10000);
}

void unconcious()
{
        die ();
}
