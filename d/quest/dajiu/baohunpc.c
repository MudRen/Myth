// by stey
// modify by mudring

#include <ansi.h>

inherit JOBNPC;

void leave();
object owner() {return query("owner");}
#include "bh_npc.h"

string *names = ({
  "����", "����", "̫������", "õ�廨��", "�ž黨��",
  "����", "��ĵ����", "��������", "ӣ����", "��β�ͻ���",
  "��÷������", "�����ӻ���", "��ͥ����", "�������㻨��",
  "����ܰ����", "�����ǻ���", "ҹ���㻨��", "�һ�����",
  "�滨����", "�Ͼ�������", "ʯ����", "�ӻ�����",
  "�϶��㻨��", "ܽ�ػ���", "Ǿޱ����", "�ﺣ�Ļ���",
  "ʯ�񻨻���", "���ٻ���", "�黨��", "��ĵ������",
  "�Һ���", "��ٺϻ���", "��������",
});

void setname()
{
    object ob = this_player();
    int i;
    string name;
    i=random(sizeof(names));
    name=names[i]+(random(2)?"Ů":"��");

    set_name(name, ({ob->query("id") + " hua xian"}));
}

void create()
{
    setname();
    set("age", 100+random(80));
    set("gender", "Ů��");
    set("attitude", "friendly");
    set("max_gin", 1000);
    set("food", 10000);
    set("water", 10000);
    set_weight(30000);
    set("no_steal",1);
    set("class","xian");
    set("taskguai",1);
    set("chat_chance", 5);
    set("chat_msg", ({
        (: random_move :)
    }) );

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: cast_spell, "mihun" :),
        (: cast_spell, "arrow" :)
    }));

    set_temp("apply/armor", 400);
    set_temp("apply/damage", 100);

    setup();

    carry_object("/d/obj/cloth/tianyi.c")->wear();
    carry_object("/d/9ct/zb/sword")->wield();
    carry_object("/d/9ct/zb/pifeng")->wear();
    carry_object("/d/ourhome/obj/shoes")->wear();
}

void init()
{
    object me=this_object();
    object who=this_player();

    add_action("do_no","ji");
//    add_action("do_qk","cast");
    add_action("do_block","",1);
    add_action("do_healup", "heal");

    if (who == owner())
    {
       add_action("do_baohu", "baohu");
       add_action("do_baohu", "dajiu");
    }
}

int do_qk(string arg)
{
    string cast_id,cast_name;
    object who = this_player();

    if (sscanf(arg, "%s on %s", cast_id,cast_name) == 2)

    if (cast_id=="qiankun" || arg=="qiankun")
   
    tell_object(who,"��������������Ԫ���ɵ�������������ͽ����Ҫ�����ҹ��з�����\n");

    return 1;
}

int do_healup()
{
    object who = this_player();
    object ob = this_object();
    if (ob->query("kee")>(ob->query("max_kee")-20))
    {
        message_vision("$N˵����лл!\n$N��ɫ����\n",ob);
        return 1;
    }
    if (who->query("kee") < 300 || who->query("force")<1000)
    {
        tell_object(who,"����ɫ���\n");
        return 1;
    }

    who->add("force", -300);
    ob->add("kee", 50);
    message_vision("$N�ܵ���$n����������!\n$N����ɫ�������ö��ˡ�\n",ob,who);

    return 1;
}
 
int do_no(string arg)
{
    object who = this_player();
    object me = this_object();
    message_vision("$N������첻֪���ʲô��$n����Ķ���$N��\n",who,me);
    return 1;
}

int do_baohu()
{
    object me =this_player();
    object ob2 = this_object();
    object killer;
    object env;
    int i;
     
    if (me != owner())
    {
        message_vision(CYN"$N˵�����㲻���ҵȵ��Ǹ��ˡ�����������\n"NOR,ob2);
       
        return 1;
    }

    if (me->is_busy())  return notify_fail("����æ���ء�\n");           
    me->command("say ����Ҳ������һ����ʤ���߼�������");

    if (!me->query_temp("baohu/kk"))
    { 
        env = environment(ob2);
        for (i = 1; i <= 3; i++)
        {
            killer = new(__DIR__"killer");
            killer->invocation(me);
            if (killer->move(env))
            {
                message_vision ("\n"+killer->query("name")+"ͻȻ���˳���......\n", me);
                killer->command("follow hua xian");
                killer->kill_ob(ob2);
            }
        }
        me->delete_temp("baohu/done");
        me->delete_temp("baohu/killer");
        me->set_temp("baohu/kk", 1);
    }

    return 1;
}

void unconcious()
{
    die();
}

void die ()
{
    object ob = query_temp("last_damage_from");
    object me = this_object();
    object where = environment (me);
       
    if (ob != owner())
    {
        message_vision(CYN"$N˵�������书̫���ˣ������ң��㡣������"
            "��������졣ɱ�ġ�����\n$N���������ˡ�\n"NOR,
            me);
    //    destruct (me); 
    leave();
        return;
    }

    message_vision(CYN"$N˵�������书̫���ˣ������ң��㡣������"
        "��������졣ɱ�ġ�����$N���������ˡ�\n"NOR,
        me);
        
    me->delete_temp("baohu");
    me->clear_condition("dajiu_job");
    me->apply_condition("job_busy", 10 + random(5)); // 60-90 sec
    if (me->query("baohuhuaxian") > 2)
        me->add("baohuhuaxian", -2);

    leave();
}

void leave()
{
    if (this_object())
    {
        if (environment())
        {
            message("vision",HIB + name() + 
                "��Ϊ���ϵ�һ���ʻ���\n" NOR,environment());
        }
        destruct(this_object());
    }

    return;
}

void heart_beat()
{
    object guai = this_object();

    if (!query_temp("weapon") && !query_temp("added"))
    {
        set_temp("added", 1);
        set("force_factor",200);
        add("force",2000);
    }
    if (query("eff_kee") < query("max_kee"))
    {
        if (random(10)<5)
        {
            command("eat yao");
        }
    }

    ::heart_beat();
}

int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    if (!userp(who)) return 0;
       
    if (who->query_temp("baohu_kill")==0) return 0;
       
    if (verb!="go"
        && verb!="fly"
        && !(environment() 
        && environment()->query("exits/" + verb)))
    {
        return 0;
    }
    
    t= random(1);
   
    if (t==1)
    {
        message_vision("$n����$N����������ˡ�\n",me,who);
        return 0;
    }
   
    message_vision("$Nһ��������$n��ǰ�������е���\n"+
        " �����֣����������ң���Ҫ���ˡ�\n\n",me,who);
    tell_object(who,me->name()+"һ����ס���㣡\n");
    return 1;
}
