// monkey.c

inherit NPC;
#include <ansi.h>

int ask_chenxiang ();

void create()
{
        set_name("С����", ({ "xiao houzi","xiaohouzi","monkey","hou" }) );
        set("long", "һֻ�ͳ��㾭�����С���ӡ�\n");
        set("gender","����");
        set("age", 6);
        set("per",20+random(5));
        set("str", 30);
        set("cor", 26); 
        set("combat_exp", 50);
  set("daoxing", 0);

            set_skill("dodge",20);
            set_skill("unarmed",10);
        set("limbs", ({ "ͷ��", "����", "ǰצ", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 10);
        set("chat_msg", ({
                (: call_other, this_object(), "random_move" :),
                "С����˵����������������ѽ��\n",
                "С����˵�����⼸���治֪�������ڸ���\n",
                "С����˵���������Ҹ���ô�����أ�\n",
                "С����˵��������ͳ���ú���һ�¡�\n" }) );

          set("inquiry", ([
    "����" : (: ask_chenxiang :),
    "chenxiang" : (: ask_chenxiang :),
  ]) );

       setup();
}


int ask_chenxiang ()
{     
        object ob;
ob = new ("/d/quest/bld/npc/chenxiang");

        if (this_player()->query("bld/done") == 1)
        {
               command("heng");
               command("say �㶼�ȹ��˻������ң� \n");
               return 1;
        }
         
if (this_player()->query("bld/monkey") == 1)
return notify_fail("�㲻��֪������ \n");

        command("heihei");
        command("say ����ʶ����ˣ� \n");
        command("say ������ڻ���ɽŶ���Լ�ȥ���Ұɣ� \n");
        command("addoil");
        command("say ���ˣ���ȥ�ҳ����ˣ� \n");
        message_vision("С����һ��������ʧ�ˣ� \n",this_player());
        this_player()->set("bld/monkey",1);
ob->move("/d/dntg/hgs/flowerfruit");
        destruct(this_object());
        return 1;
}

