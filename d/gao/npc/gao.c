//Cracked by Roath
// happ@YSZZ
 
// gao.c
#include <ansi.h>

inherit NPC;
string ask_girl();

void create()
{
       set_name("��Ա��", ({"gao yuanwai", "gao"}));

set("long","�߼�ׯ�����ˣ��Ե��ֺ����ģ�\n��˵�����Ӧ���ֺǺǵأ���ȴ��ü����������������ʲô���£�\n");
       set("gender", "����");
       set("age", 46);
       set("title", "ׯ��");
       set("attitude", "peaceful");
       set("shen_type", 1);
   set("combat_exp", 5000);
        set_skill("unarmed", 15);
   set_skill("dodge", 30);
   set_skill("parry", 15);
set("inquiry", ([
"name": "�Ϸ��ոߣ����Ǽ��е����ˣ�\n",
"here": "����ׯ��Ҳ��\n",
"��С��": (: ask_girl :),
"����" : (: ask_girl :),
]) );

   setup();
       add_money("silver", 3+random(5));
   carry_object("/d/ourhome/obj/choupao")->wear();
}


void init()
{
        remove_call_out("check");
        call_out("check",1);
}

void check()
{
          object room = environment();
          object lady = present("cui lan",room);        
          object ob;
          if (!lady) return ;
          if( lady->query_leader() == 0 )
                return ;
          ob = present(lady->query_leader(),room);
          if( ob == 0 )
                return ;
          remove_call_out("check2");
          call_out("check2",1,ob);
}
void check2(object ob)
{
          int i;

//          if(! ob->query("obstacle/hf") )
//                return;
          if (ob->query("obstacle/yz") == "done")
                return;
          if( !ob->query_temp("pig_killed") )
                return;

        i = random(500);
        ob->add("obstacle/number",1);
        ob->set("obstacle/yz","done");
        ob->add("combat_exp",i+2000);
        command("chat ��л"+ob->query("name")+"�ȳ��ҵ�СŮ������");
        message("channel:chat",HIY"������ն������������(guanyin pusa)��"+ob->query("name")+"��������ȡ��[1;37m����أ�\n"NOR,users());
        tell_object (ob,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
        ob->delete_temp("pig_killed");
        ob->save();
        return;
}


string ask_girl()
{
        object ob = this_player();
        object cloth = new("/d/gao/obj/cloth");

        if( ob->query("obstacle/yz") == "done" 
        || !ob->query("obstacle/hf") 
        || ob->query_temp("girl_asked") )
                {
                command("?");
                return("�������ʲô��");
                }

        command("disapp1 gao");
        command("cry1");
        cloth->move(ob);
        ob->set_temp("girl_asked",1);
        command("say ����Ů����������ɽһ��Ұ��ְ�ռ�ˣ���֪����û���ֶΣ����ҾȻ�Ů���� ");
        return("��������ǰ�����·���");       
}        
