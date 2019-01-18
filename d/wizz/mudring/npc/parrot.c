// By jpei@sj

#include <ansi.h>

inherit NPC;

string ask_name();
string ask_caishen();
string ask_password();
string ask_greatwall();

//string keep_msg = 0;
object follow_ob = 0;
int password_try = 0;

void create()
{
        set_name("����", ({ "parrot", "yingwu" }) );
        set("race", "Ұ��");
        set("gender", "����" );
        set("age", 2);
        set("long", "һֻ��˵����С�����ġ�\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("verbs", ({ "claw", "poke" }) );

        set("str", 15);
        set("dex", 100);
        set("con", 15);
        set("int", 20);

        set("combat_exp", 800);

        set_skill("dodge", 500);

        set_temp("apply/attack", 6);
        set_temp("apply/defense", 6);
        set_temp("apply/dexerity", 100);
        set_temp("apply/armor", 3);

        set("inquiry", ([
                "name": (: ask_name :),
                "rumors": "��˵�ձ���Ҳ��Ѱ����ʿ�����Ǹ��ʻ������롣",
                "here": "���ֲ����ˣ���ô֪������",
                "����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
                "jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
                "����" : "����ʶ�𣿾��������ڵ�����ѽ��",
                "mudring" : "����ʶ�𣿾��������ڵ�����ѽ����",
                "���ɶ�" : "�����㲻������������֪���ɣ���",
                "С��" : "�ٺٺ١���",
                "xianzi" : "ȥ�ʷ���ɣ�",
                "����" : "�ⶼ��֪����ȥ����������š���",
                "�ʻ�" : "�ȶ��ϰ����ٸ������룡",
                "����" : (: ask_caishen :),
                "���ﳤ�����ﳤ": (: ask_greatwall :),
                "����": (: ask_password :),
        ]));

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: force_me, "!!!" :),
        }));
        set("chat_chance", 5);
        set("chat_msg", ({
                (: force_me, "chicken" :),
        }));

        setup();
        set("race", "����");
        set("can_speak", 1);
}

void init()
{
        object ob = this_player();

        add_action("do_let", "let");
        ::init();
        if (objectp(follow_ob) && !present(follow_ob, environment(this_object())))
                call_out("continue_follow", 1, follow_ob);
}

int continue_follow(object ob)
{
        if (objectp(ob) && !present(ob, environment(this_object()))) {
                say("���ĺ�Ȼ�������ˡ�\n");
                move(environment(ob));
                message_vision("���ķ��˹�����ͣ��$N�ļ���ϡ�\n", ob);
        }
}

int do_let(string arg)
{
        object ob = this_player();
        string myid, todie;

        if (!arg || sscanf(arg, "%s %s", myid, todie) < 2)
                return notify_fail("������ʲô��\n");
        if (!id(myid)) return notify_fail("����˭��ʲô��\n");
        if (todie != "to die" && todie != "ȥ��" && todie != "die")
                return notify_fail("������������ʲô��\n");
        if (ob != follow_ob) return notify_fail("���ĲŲ������أ�\n");
        message_vision("$N�������ĺȵ�������ȥ���ɣ���\n", ob);
        command("inn " + ob->query("id"));
        command("deadlove parrot");
        die();
        return 1;
}


void relay_say(object ob, string msg)
{
        int i;

        if (!msg) return;
    say(CYN + name() + "�ظ�����" + msg + "\n" + NOR);
}

void relay_emote(object me, string arg)
{
        switch (arg) {
                case "die":
                case "idle":
                case "sure":
                case "lazy":
                case "xbc97":
                case "smell":
                case "bored":
                case "escape":
                case "chicken":
                case "laughproud":
                case "nonsense":
                        command(arg);
                        break;
                case "waggle":
                case "willbe":
                case "pain":
                case "push":
                case "puke":
                case "poke":
                case "stare":
                case "admit":
                case "rascal":
                case "story":
                case "crazy":
                case "thank":
                case "name1":
                case "disapp":
                case "disapp1":
                case "accuse":
                case "homework":
                case "papaya":
                case "benger":
                case "sue":
                case "regard":
                case "courage":
                case "meeting":
                case "pat":
                case "pig":
                case "piggy":
                case "flower":
                case "joke":
                case "sigh":
                case "poor":
                case "ugly":
                case "rabbit":
                case "pretty":
                case "knife1":
                case "grpfight":
                case "points":
                case "congra":
                case "sing3":
                case "lover":
                case "nocry":
                case "flatter":
                case "rabbit2":
                case "goodkid":
                case "fire":
                case "boat":
                        command(arg + " parrot");
                        break;
                case "interest":
                        command("liar");
                        break;
                case "slow":
                        command("lover");
                        break;
                case "shout":
                        command("peace");
                        break;
                case "bug":
                case "cook":
                        command("taste");
                        break;
                case "hero":
                case "hehe":
                        command("fear");
                        break;
                case "cold":
                case "sing2":
                case "magic":
                case "taste":
                        command("escape");
                        break;
                case "inn":
                case "sorry":
                case "careful":
                        command("sneer");
                        break;
                case "kick":
                case "slap":
                case "trip":
                        command("pain");
                        break;
                case "fire1":
                case "swear":
                        command("shake");
                        break;
                case ":)":
                case "haha":
                case "xixi":
                case "laugh":
                case "hehehe":
                case "giggle":
                        command("nosmile");
                        break;
                case "claw":
                        command("cry");
                        break;
                case "!!!":
                case "gun":
                case "club":
                case "hug":
                case "drug":
                case "doubt":
                case "makeup":
                        command("corpse parrot");
                        break;
                case "shameless":
                        command("hate parrot");
                        break;
                case "admire":
                        command("humble parrot");
                        break;
                case "joythank":
                        command("thank parrot");
                        break;
                case "rhero":
                        command("shout parrot");
                        break;
                case "poem":
                        command("raise parrot");
                        break;
                case "slogan":
                        command("slogan2 parrot");
                        break;
                case "angry":
                        command("stare parrot");
                        break;
                case "happy":
                        command("rich parrot");
                        break;
                case "dare":
                        command("points parrot");
                        break;
                case "lick":
                        command("smell parrot");
                        break;
                case ":(":
                case "cry":
                        command("nocry " + me->query("id"));
                        break;
                case "xigua":
                        command("xigua2 " + me->query("id"));
                        break;
                case "nod":
                        command("shake " + me->query("id"));
                        break;
                case "shake":
                        command("nod " + me->query("id"));
                        break;
                case "blush":
                        command("lover " + me->query("id"));
                        break;
                case "monk":
                        command("buddhi " + me->query("id"));
                        break;
                case "hungry":
                        command("rich " + me->query("id"));
                        break;
                case "slapsb":
                        command("inn " + me->query("id"));
                        break;
                case "wait":
                        command("nomatch " + me->query("id"));
                        break;
                case "lean":
                        command("hug " + me->query("id"));
                        break;
                case "god":
                        command("comfort " + me->query("id"));
                        break;
                case "faint":
                        command("nofear " + me->query("id"));
                        break;
                case "wanfu":
                        command("bow " + me->query("id"));
                        break;
                case "innocent":
                        command("goodman " + me->query("id"));
                        break;
                case "yawn":
                        command("zzz " + me->query("id"));
                        break;
                case "visit":
                        command("welcome " + me->query("id"));
                        break;
                case "welcome":
                        command("visit " + me->query("id"));
                        break;
                case "brag":
                        command("gun " + me->query("id"));
                        break;
                case "dunno":
                        command("disapp " + me->query("id"));
                        break;
                case "hmm":
                        command("? " + me->query("id"));
                        break;
                case "poem3":
                        command("willbe " + me->query("id"));
                        break;
                case "zzz":
                        command("shutup " + me->query("id"));
                        break;
                case "nomatch":
                        command("mother " + me->query("id"));
                        break;
                case "nofear":
                        command("chicken " + me->query("id"));
                        break;
                case "meet":
                case "smell1":
                        command("seduce " + me->query("id"));
                        break;
                case "rose":
                case "kiss1":
                        command("kiss " + me->query("id"));
                        break;
                case "rich":
                case "protect":
                        command("joythank " + me->query("id"));
                        break;
                case "hammer":
                case "killair":
                        command("peace " + me->query("id"));
                        break;
                case "uncle":
                case "anniversary":
                        command("sure " + me->query("id"));
                        break;
                case "cut":
                case "corpse":
                case "soup":
                case "smash":
                case "slash":
                case "knife":
                        command("peace1 " + me->query("id"));
                        break;
                case "thumb":
                case "mother":
                case "praise":
                case "goodman":
                case "applaud":
                case "handsome":
                        command("noshame " + me->query("id"));
                        break;
                case "bf":
                case "gf":
                case "chitchat":
                        command("nonsense " + me->query("id"));
                        break;
                case "wave":
                case "bye":
                case "byebye":
                case "goodbye":
                        command("slow " + me->query("id"));
                        break;
                case "rob":
                case "fat":
                case "dumb":
                case "uncle":
                case "u&me5":
                case "congra1":
                case "marriage":
                        command("faint " + me->query("id"));
                        break;
                case "love":
                case "lovelook":
                case "loveshoe":
                case "deadlove":
                case "ghostlove":
                case "joycup":
                case "touch1":
                case "wink":
                case "u&me2":
                case "xigua2":
                case "sex":
                case "seduce":
                case "doufu":
                case "oath":
                case "flirt":
                        command("puke " + me->query("id"));
                        break;
                case "nosmile":
                case "brother":
                case "massage":
                        command("goodkid " + me->query("id"));
                        break;
                case "ysis":
                case "sister":
                case "aunt":
                case "18mo":
                case "beauty1":
                case "shajiabang1":
                        command("uncle " + me->query("id"));
                        break;
                case "bite":
                case "grin":
                case "hate":
                case "consider":
                        command("fear " + me->query("id"));
                        break;
                case "flush":
                case "u&me1":
                case "kill1":
                case "callname":
                        command("shout " + me->query("id"));
                        break;
                case "agree":
                case "u&me":
                case "raise":
                        command("u&me5 " + me->query("id"));
                        break;
                default:
                        command(arg + " " + me->query("id"));
                        break;
        }
}

int return_home(object home)
{
        // At home already?
        if (!environment() || environment()==home)
                return 1;

        // Able to leave?
        if (!living(this_object()) || is_fighting()) return 0;

        if (!follow_ob || !objectp(follow_ob)) {
                message("vision", this_object()->name() + "����ææ�ط����ˡ�\n",
                        environment(), this_object());
                if (move(home)) {
                        message("vision", this_object()->name() + "����ææ�ط��˹�����\n",
                                environment(), this_object());
                        return 1;
                }
                return 0;
        }
        return 1;
}

string ask_name()
{
        if (this_player()->query_temp("parrot"))
                return "�Ҿ��ǲ���";
        else
                return "��û���ɣ�����Ҳ��������";
}

string ask_password()
{
    if (this_player()->query_temp("parrot")) {
      if (!follow_ob) {
        set("name", this_player()->name()+"������");
        follow_ob = this_player();
        set_leader(this_player());
        this_player()->delete_temp("parrot");
      }
                return "������Ȼ�������Ǻܺüǣ�43420 024 420 ��˱顣";
    }
        else {
                if (password_try < 16012345) password_try += random(10) + 1;
                return "ʲô���룿jpei�ĵ�¼������������" + chinese_number(password_try) + "���ˣ���û�Գ���....";
        }
}

string ask_caishen()
{
        if (this_player()->query_temp("parrot"))
                return "��������ҡ�";
        else
                return "�뷢������ˣ���";
}

string ask_greatwall()
{
        this_player()->set_temp("parrot", 1);
        return "���ĺ��������硣";
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        message_vision("$N����������¶��֣���Ȼ�������˸���ͷ��һ�����ﱣ�������ߺȵ������밮��С�����\n", ob);
}

int accept_fight(object ob)
{
        message_vision("���Ķ���$N��У���" + RANK_D->query_rude(ob) + "���б���ɱ��ѽ����\n", ob);
        return 0;
}


