
/* <SecCrypt CPL V3R05> */
 
// laoren.c
//ssdd...10/23/99.
//lizuole 99.11.12
#include <ansi.h>
#include <login.h>
inherit NPC;

void create()
{
        set_name(HIR"��������"NOR, ({"lao ren","laoren","ren"}));
        set("title",HIC"���ʹ��"NOR);
        set("gender", "����" );
        set("age", 168);
        set("class","taoist");
        set("long", "��λ���˿���ȥһ�ٶ��꣬�ֳ��ְ׵ķ���ֱ�䵽�أ������Ŀ���д������С�\n");
        set("combat_exp", 8000);
        set("attitude", "peaceful");
        set_skill("unarmed", 1000);
        set_skill("dodge", 2000);
        set_skill("parry", 2000);
        set_skill("literate", 500);
        set_skill("spells", 5000);
        set("per", 150);
        set("max_kee", 3500);
        set("max_gin", 3000);
        set("max_sen", 3000);
        set("max_mana", 2000);
        set("mana", 2000);
        set("mana_factor", 500);
        setup();
      //  carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("/d/obj/cloth/linen")->wear();
       // carry_object("/d/obj/book/chunyang")->tear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 3);
        set("inquiry", ([
                "name" : "�Ϸ�������������ʹ�ߣ������ٺ١�\n",
                "here" : "��û������������ط��������µ�һ�������ڡ�\n", 
   ]) );

        set("chat_msg", ({
                "�������˸���˵����������ҿ��Ե����������츣����\n",   
                //"���������������´������㼸�ۡ�\n",
                "�������˸���˵������ҿ����츣��ѽ��\n",
                "�������˻��˻ξ�ƿ��Ц����������û���ë�������Ǻõ������\n",

       }) );
}

/*int accept_object(object me, object ob)
{
   object xiannidan;

     if ((string)ob->query("name")!="�𻨾ƴ�") {
            command("say ��̫�����ˣ������𡣡�������");
     command("give " + ob->query("id") + "to " + me->query("id"));
            return 1;
        }
        else {
     command("u&me " + me->query("id"));
            command("say ��λ" + RANK_D->query_respect(me) + "����������׳��˳��⡣\n��ĳ���ж�����������������һ�����൤��\n");
           carry_object("/d/obj/book/chunyang");
           command("give book to " + me->query("id"));
            return 1;
        }
}  */
/*int accept_object(object me, object ob)
{
   object nowords;
   if ( me->query("xnd") == "�Թ���" ){
  	  command("kick " + me->query("id"));
          command("say �Ҷ��������ˣ�������������ƭ��");
          //command("give " + ob->query("id") + "to " + me->query("id"));
          return 1;}
    else{        
     if ((string)ob->query("name")!="�𻨾ƴ�") {
            command("say ���ҵ����ҵ���������̫�����ˡ�");
            command("give " + ob->query("id") + "to " + me->query("id"));
            return 1;
        }
        else {
            command("u&me " + me->query("id"));
            command("say ��λ" + RANK_D->query_respect(me) + "����������׳��˳��⡣\n��ĳ���ж�����������������һ�����൤��\n");
           carry_object("/d/obj/book/nowords");
           command("give nowords to " + me->query("id"));
           me->set("xnd", "�Թ���");
            return 1;
        }
       } 
}*/

int accept_object(object me, object ob)
{
   object xnd;
 
     if ((string)ob->query("name")!="�𻨾ƴ�") {
            command("say �Ǻǣ��㵽��ͦ������ƨ�ϡ�");
            //command("give " + ob->query("id") + "to " + me->query("id"));
            return 1;
        }
        else {
           if ( me->query("xndf") == "������" ){
  	       command("kick " + me->query("id"));
               command("say �Ҷ��������ˣ�������������ƭ��\n��Ҫ������ƭ�ң��ҿ�Ҫ��������!");
               command("say ������������������˼ҵ���ƨ���Ͼ�������һ��,�²�Ϊ��ѽ!");
               return 1;}
	     else{
               command("u&me " + me->query("id"));
               command("say ��λ" + RANK_D->query_respect(me) + "����������׳��˳��⡣\n" + me->query("name") + "�ĳ���ж���������������" + me->query("name") + "һ�����൤��\n");
               carry_object("/obj/xnd");
               command("give xnd to " + me->query("id"));
               me->set("xndf", "������");
               return 1;
                 }
             } 
}

