inherit NPC;

int give_dan();

#define UPPLAYER   "/cmds/wiz/update"

#include <ansi.h>

void create()

{

  set_name("���ƻ�ӭ��ʹ", ({ "doudou" }) );

        set("gender", "Ů��" );

      set("color", HIR); 

         set("age", 9);

        set("age", 20);

           set("title", HIY "��"+ HIR "��" + HIM "��" + HIC"��" NOR);

        set("long",

                HIM "MUDΪ�����Ϳ�,ϣ�������ĸ���\n" NOR);

        set("combat_exp", 5000000);

        set("attitude", "friendly");

        set("per",50);

        set_skill("unarmed",200);

            set_skill("dodge",200);

        set("inquiry", ([

                "����" : (: give_dan :),

            ]));

        setup();

}

int give_dan()

{

object dan;

object who;

who = this_player();

if (!userp(who))

{

command("heng");

command("say ʲôСèС��Ҳ��Ҫ���ﰡ����");

command("qi");

return 1;

}

         if ((string)this_player()->query("passionset")=="1")

{

          message_vision("$N����$n����һ����\n",this_object(),this_player());

       command("say ����˭ѽ������Ǽǹ���ѽ��");

  return 1;

}

if ( who->query("mudage") < 6100 ) 
{
who->set("title","����");
message_vision(HIY"$N����ɢ��ҫ�۵Ľ��!\n$N��һָ�����������$n���ϡ�\n"NOR,this_object(),this_player());
message_vision(HIW"��ӭ$n���������߿�վ,ף$n�ڱ�վ��ĸ��ˡ�\n"NOR,this_object(),this_player());
who->set("passionset","1");
UPPLAYER->update_player(who);
 return 0;
}




/*
message_vision(HIY"$N����ɢ��ҫ�۵Ľ��!\n$N��һָ�����������$n���ϡ�\n"NOR,this_object(),this_player());

message_vision(HIW"��ӭ$n���������߿�վ,ף$n�ڱ�վ��ĸ��ˡ�\n"NOR,this_object(),this_player());

who->set("passionset","1");

UPPLAYER->update_player(who);

*/
message_vision(HIW"�㲻�������ˣ�����Ŭ���ɡ�\n"NOR,this_object(),this_player());
 return 1;

}




