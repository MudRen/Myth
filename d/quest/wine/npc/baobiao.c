// baobiao.c  
// created by kuku@sjsh 2002/12

#include <ansi.h>
inherit NPC;

string* dart_area=({"/d/city/dangpu","/d/dntg/hgs/pownshop","/d/city/bank",
"/d/kaifeng/dangpu"});
string* dart_short=({"���ǵ���","��ҵ���","���Ǯׯ","����"});
string* dart_id=({"dong pusheng","wu benqian","tie suanpan","xu laoban"});
string* dart_name=({"������","�ⱾǮ","������","���ϰ�"});

string do_job();
int do_give();
int ask_cancel();

void create()
{
        set_name("���", ({ "li chaofan", "li"}));
        set("gender", "����");
        set("age", 45);
        set("title", "��Զ�ھ�����ͷ");
        set("long", "�����ǡ���Զ�ھ֡�������ͷ���������\n");
        set("combat_exp", 30000);
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 50);
        set_skill("force", 40);
        set("per",19);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("inquiry", ([ 
                "����" : (: do_job :),
                "��"   : (: do_job :),
                "����" : (: do_job :),
                "job"  : (: do_job :),
                "�׾�" : (: do_give :),
            "����" : (: ask_cancel :),
                 ]) );
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);
        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/cloth/linen")->wear();
}

string chinese_time(int t)
{
        int d, h, m, s;
        string time;
        s = t % 60;     t /= 60;
        m = t % 60;     t /= 60;
        h = t % 24;     t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "��";
        else time = "";
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        return time;
}

string do_job()
{   
    int n;
    object ob,cart;
    ob=this_player(); 
    n=random(sizeof(dart_area));   

    if ( ob->query_temp("in_dart"))
       return "�㲻�ǲ�Ҫ��������\n";

    if ( !ob->query("wine/start") || !present("jiu pai",ob)) 
       return "������û��������㡣\n";

    if ( (int)ob->query_condition("dart_limit" ) > 0 )
       return "�����û�������ɡ�\n";

    if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "��������æ���ء�\n";

    if ( (int)ob->query("combat_exp") < 200000 )
       return "�����Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(ob)+"�ƺ�û����������\n";

    if ( (int)ob->query_skill("force") < 60 )
       return "�����Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(ob)+"�Ļ����������㣡\n";
    if ( (int)ob->query("level")< 30)
       return "��λ"+RANK_D->query_respect(ob)+"����ĵȼ�̫�ͣ�����Ҫ��������\n";

    ob->set_temp("in_dart",1);
    ob->set_temp("dart_area",dart_area[n]);
    ob->set_temp("dart_id",dart_id[n]);
    ob->set_temp("dart_name",dart_name[n]);
    ob->apply_condition("dart_limit", 60);

    cart=new(__DIR__"cart");
    cart->set("master",ob->query("name"));
    cart->set("masterid",ob->query("id"));
    cart->move("/d/quest/wine/biaoju");
    command("nod");
    message_vision(CYN "������ƽ������˳�����\n" NOR,ob); 
CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"���ڳ�����Զ�ھֳ�����,��ﲢ�����ϰ�!");
    return ob->name(1)+"�����������͵�"+dart_short[n]+"��"+dart_name[n]+"���С�\n";
}

int do_give()
{
        int tt;
        object ob,jiu;
        ob=this_player();
        tt=ob->query("wine/mijiu");
        if ( !ob->query("wine/start") || !present("jiu pai",ob)) 
            {command("say ����û�����־ơ�\n");
              return 1;}
        if ( !ob->query_temp("in_dart"))
            {command("say ��Ҫ����Ҫ�Ȱ�����Щ������\n");
             return 1;}
        if ( !ob->query_temp("over_dart") )
            {command("say ��Ҫ��Ҫ������Ҹ��������\n");
            return 1;}
        if( tt) 
         { if(tt<=time() && time()<tt+2400) 
        { message_vision("\n"+this_object()->query("name")+"˵�������Ҫ���ƣ��ȵ������ɡ�\n",ob); 
            return 1; } 
        }
        ob->delete_temp("in_dart");
        ob->delete_temp("over_dart");
        ob->delete_temp("dart_name");
        ob->delete_temp("dart_id");
        ob->delete_temp("dart_area");
        jiu=new("/d/quest/wine/obj/mijiu");
        jiu->move(ob);
        ob->set("wine/mijiu",time());
        command("pat "+ob->query("id"));
        command("say ����������һ�����ȱ���ɡ� \n"); 
        message_vision("$N����$nһ��"+jiu->query("name")+"��\n", this_object(),ob);
        return 1;
}

int ask_cancel()
{
         object ob=this_player();
         if ( !ob->query_temp("in_dart"))
           return notify_fail("����������\n");
         ob->delete_temp("in_dart");
         ob->delete_temp("dart_name");
         ob->delete_temp("dart_id");
         ob->delete_temp("dart_area");
         ob->apply_condition("dart_limit", 0);
         command("say �´οɲ�����������\n");
         return 1;
}
