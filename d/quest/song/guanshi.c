// guanshi.c 
// modified by koker@sjsh2002

#include <ansi.h>
inherit NPC;

string* dart_area=({"/d/dntg/hgs/schoolhall","/d/moon/yltw"});
string* dart_short=({"���������","�¹�������������"});
string* dart_id=({"dongfang boyu","jiaofu tou"});
string* dart_name=({"������������","�η�ͷ"});
 
string do_job();
string do_give();
string do_cancel();

void create()
{
        set_name("��ݹ���", ({"guan shi", "oldman"}));
        set("title", "������");
        set("gender", "����");
        set("age", 70);
        set("long", "��Ӣ������Զ����ݹ��¡�
���ھ���Զ����������������������������ž�����������\n");

        set("combat_exp", 70000);
        set_skill("fonxansword", 70);
        set_skill("sword", 70);
        set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("moondance", 70);
        map_skill("dodge", "moondance");
        map_skill("sword", "fonxansword");
        map_skill("parry", "fonxansword");
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 30);
        set("inquiry", ([
                "�˻�" : (: do_job :),
                "��"   : (: do_job :),
                "����" : (: do_job :),
                "job"  : (: do_job :),
                "����" : (: do_give :),
                "over" : (: do_give :),
                 "����" : (: do_cancel :),
                 "cancel" : (: do_cancel :),
        ]) );
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);
        setup();
//        carry_object("/clone/weapon/changjian")->wield();
//        carry_object("/clone/misc/cloth")->wear();
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
{   int n;
    object ob,cart;
    ob=this_player(); 
    n=random(sizeof(dart_area));   

    if ( ob->query_temp("in_dart"))
       return "�㲻�ǲ�Ҫ��������\n";

    if ( (int)ob->query_condition("dart_limit" ) > 0 )
       return "�����û�������ɡ�\n";

    if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "��������æ���ء�\n";

    if ( (int)ob->query("combat_exp") < 100000 )
       return "���ҵĻ��Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(ob)+"�ƺ�û����������\n";

    if ( (int)ob->query_skill("force") < 60 )
       return "�˻��Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(ob)+"�Ļ����������㣡\n";

    ob->set_temp("in_dart",1);
    ob->set_temp("dart_area",dart_area[n]);
    ob->set_temp("dart_id",dart_id[n]);
    ob->set_temp("dart_name",dart_name[n]);
    ob->apply_condition("dart_limit", 60);

    cart=new(__DIR__"cart");
    cart->set("master",ob->query("name"));
    cart->set("masterid",ob->query("id"));
    cart->move("/d/city/bingqipu");
    command("nod");
    message_vision(CYN "������ƽ��������˳�����������ƥ��\n" NOR,ob); 
    return "������������Ļ��͵�"+dart_short[n]+"��"+dart_name[n]+"���С�\n";
    
}

string do_give()
{
string msg;
  object ob;

  ob=this_player();

  if ( !ob->query_temp("in_dart"))
    return "��û�����˻�����\n";

  if ( !ob->query_temp("over_dart") )
    return "����û���͵���ͷ��Ī���������ˣ���\n";

  ob->delete_temp("in_dart");
  ob->delete_temp("over_dart");
  ob->delete_temp("dart_name");
  ob->delete_temp("dart_id");
  ob->delete_temp("dart_area");
  
if (ob->query("weiwang") < 200)
{
    ob->add("combat_exp",random(500)+50);
//    ob->add("potential",random(200)+50);
    ob->add("balance",random(1000)+500);   
    ob->add("daoxing",random(10000)+500);   
    ob->add("weiwang",5);
      msg = ob->name()+"�����һ���˻�����õ��˽���"; 
      MONITOR_D->report_system_msg (msg); 
    return RANK_D->query_respect(ob)+"��Ȼ�ǰѺ��֣������ġ�\n�������"CYN"��������"NOR"̫�٣��Ҳ��ܸ���ȫ���Ӷ���ˣ�����������ðɣ�\n"NOR;  
}
else {
    ob->add("combat_exp",random(20000)+5000);
    ob->add("potential",random(20000)+5000);
    ob->add("balance",random(30000)+3000); 
    ob->add("daoxing",random(100000)+30000); 
    ob->add("weiwang",-200);                   
}
  msg = ob->name()+"�ڱ����̵õ���������ȫ���";
  MONITOR_D->report_system_msg (msg);
  command("pat "+ob->query("id"));
  return RANK_D->query_respect(ob)+"���ʮ�ָ�л���ܰ������˻����Ǳߣ�̫�鷳���ˡ�\n��������"YEL"ȫ��Ӷ��"NOR"��ϣ�����´����������ͻ������Ǻ���Ҫ���������˲ţ�\n"NOR;
}

// passion add
string do_cancel()
{
object ob;
ob=this_player();
  if ( !ob->query_temp("in_dart"))
   return "��ʲô�㣬����û���������\n";
ob->delete_temp("in_dart");
ob->delete_temp("dart_area");
ob->delete_temp("dart_id");
ob->delete_temp("dart_name");
ob->clear_condition("dart_limit");
command("sigh");
message_vision(CYN "�������ˣ��ٸ���һ�λ���ɡ�\n" NOR,ob); 
return "�´κú��������ڶ������ˡ�\n";
}
