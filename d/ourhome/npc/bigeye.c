//Cracked by Roath
// bigeye.c
// 1996/12/06 by cglaem
#include <ansi.h>
inherit NPC_SAVE;
string send_mail();
string receive_mail();
nosave int i;

void create()
{       reload("jiangrobot");
        set_name("ǧ����", ({"qianli yan", "bigeye", "youchai","chai" }) );
        set("title", HIG"�ʲ�"NOR);
        set("gender", "����" );
        set("age", 30);
        set("str", 40);
        set("long",
                "ǰ��ʴ�����š���Ϊ͵����Ů��ԡ������Ϊ�ʲ\n�������Ǻ�˳���һ����ڻ���ɽ��ʯ���ģ�\n�����Ӳ��������ܵ��������ˡ�\n");
        set("combat_exp", 8000);
        set("daoxing", 100000);
 
        set("attitude", "friendly");
        set("inquiry", ([
                "name":"�����㶼����ʶ������������ǧ���۾����ҡ�", 
                "here" : "��֪������ʲô�ط�����ֻ�������ŷ��š�",
                "��Ů" : "�ٺ٣������������㿳ͷ��Ҳ�����ˡ�",
                "��ʴ��" : "���������һ���Ҿ�����������ֻ���ݹٷŻ𣬲�����յ�ơ�",
                "����" : (: send_mail :),
                "����" : (: receive_mail :),
                "�ż�" : (: receive_mail :),
                "��" : (: receive_mail :),
                //"mail" : "��������������ɣ���������Ү~~~~~~~~",
                "mail" : (: receive_mail :),
                "mailbox" : (: receive_mail :),
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 50);
        set_skill("unarmed", 40);
        set("per", 15);
        set("max_kee", 500);
        set("max_gin", 100);
        set("max_sen", 300);
        set("force", 150);
        set("max_force", 300);
        set("force_factor", 0);
        setup();
        if(clonep()) {
          add_money("coin", 70);
          carry_object("/d/ourhome/obj/linen")->wear();
        CHANNEL_D->register_relay_channel("rumor");
        carry_object("/d/wiz/npc/caishen"); //note, here is a NPC.
        }
}

void relay_channel(object ob, string channel, string msg)
 {
        string who;
        if( !userp(ob) || (channel != "rumor") ) return;
        if (wizardp(ob)) return;
        who = ob->query("id");
        if( ob==this_object() ) return;
        if( msg!="" )
        {
                i+=1;
                if (i>10) i=1;
                delete("memory/"+i);
                add("memory/"+i+"/"+who,({ msg }));
        }
        else
        return 0;
}

string send_mail()
{
        object mbox;

        if( this_player()->query_temp("mbox_ob") )
                return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "��һ�µ��ϳǿ�ջ�����Ұɡ�\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "Ŷ������Ҫ������������������䣬���ŵķ�����������˵����\n";
}

string receive_mail()
{
        object mbox;

        if( this_player()->query_temp("mbox_ob") )
                return "������仹�ڰɣ������е��Ŷ������档\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "��һ�µ��ϳǿ�ջ�����Ұɡ�\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "�ã��������ң��������ˣ�����������⣬�������ɣ���������ˡ�\n";
}
void init()
{
    if( !environment()  ||  base_name(environment()) != query("startroom") )
            return;
    add_action("give_quest", "quest");

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

        if(d)
                time = chinese_number(d) + "��";
        else
                time = "";
        if(h)
                time += chinese_number(h) + "Сʱ";
        if(m)
                time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me, HIW "ǧ����˵������" + time + "��");

                return 1;
}

int give_quest()
{
        object me,letter;
        object *ob=livings();
        int i,timep;

        me = this_player();
// letter�͵����busy
        if((int)me->query("letter_over") > time())
                return notify_fail("ǧ��������ض���˵��������λ"+RANK_D->query_respect(me)+"������ȥЪϢЪϢ��\n");
        if((int)(me->query("daoxing")) > 200000)
        {
                message_vision("ǧ���۶�$N˵����λ"+RANK_D->query_respect(me)+"���и������С������������ݣ���\n",me);
                return 1;
        }
// û���������ж�
        if ((int)me->query("letter/task_time"))
        {
// û������� ������ʱ������Χ�� 
                if( ((int)me->query("letter/task_time")) >  time() )
                {
                        tell_object(me,"�����ڵ������ǰ��ż��͸�"+me->query("letter/target")+"\n");
                        write("ǧ���������Ķ���˵�� ��ð��Ű����͵�ѽ��\n");
                        return 1;
                } 
// û�������ʱ���ѹ�������busyΪ�ͷ�ʱ�䡣        
                else 
                { 
                        if(!me->query("idle_start"))
                        {
                                me->set("idle_time",time()+30+random(30));
                                me->set("idle_start",1);
                        } 
                        if(me->query("idle_time")>time())
                        {
                                write("ǧ���������Ķ���˵�����С�¶�������,�š�����\n");
                                if(me->query_temp("idle_warned")&&!me->query_temp("wait_start")) 
                                {
                                        command("heng "+me->query("id"));
                                        me->delete_temp("idle_warned");
                                        me->set_temp("wait_start",1);}
                                        if(!me->query_temp("idle_warned")&&!me->query_temp("wait_start")) 
                                        {
                                                command("idle "+me->query("id"));
                                                me->set_temp("idle_warned",1);
                                        }
                                        write("ǧ���ۺ����������������������õȵ������������ˣ�\n");
                                        return 1;
                                }
                        }
                }
                message_vision("ǧ���۶�$N˵�����������ã�������պ���һ����Ҫ�ͳ�ȥ��\n",me);
                timep = random(200) + 180;
                i=random(sizeof(ob));
// �ų��͸���ʦ����ʦ����Ŀ�µ�npc, /d/wiz�µ�npc�Ŀ�����
// �ų��͸��������50������

                while (1)
                {
                        i++;
                        if (i==sizeof(ob))
                        i=random(sizeof(ob));
                        if (ob[i]==me)  continue;
                        if (!environment(ob[i])) continue;
                        if (ob[i]->is_ghost())  continue;
                        if (wizardp(ob[i]))  continue;
                        if (random(10)==3)
                        if ( !(userp(ob[i])&&ob[i]->query("combat_exp")<500000&&!wizardp(ob[i]))) 
                        continue;
                       if (!sscanf(base_name(ob[i]),"/d/%*s" )||sscanf(base_name(ob[i]),"/d/wiz/%*s" )) continue;
                        break;
                }
                time_period(timep,me);
                if(domain_file(base_name(environment(ob[i])))=="city"||
                   domain_file(base_name(environment(ob[i])))=="gao"||
                   domain_file(base_name(environment(ob[i])))=="huanggong"||
                   domain_file(base_name(environment(ob[i])))=="sea"||
                   domain_file(base_name(environment(ob[i])))=="nanhai"
                )
                me->set("letter/basic",1);
                tell_object(me, "�����͸���" + ob[i]->short(1) + HIW +"��������������ˡ�\n" NOR);
                message_vision("$N����$nһ���š�\n",this_object(),me);
                letter = new(__DIR__+"obj/letter");
                letter->set_target(ob[i]->short(1));
// ������˿��԰�æ���ŵ�bug
                letter->set_owner(me->query("id"));
                letter->move(me);
                me->delete("idle_start");
                me->delete_temp("wait_start");
                me->set("letter/target",ob[i]->short());
                me->set("letter/task_time", (int)time() + timep);
                me->delete("letter_over");
                return 1;
}


