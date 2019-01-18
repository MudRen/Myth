// channeld.c
// 97-10-18 add intermud channel and emote capability
//      By ken@XAJH & fuyo@XAJH
// Updated by Doing for HELL
//
// �벻Ҫֱ�����߱༭���ļ���
//
// Modify By Mudring@SanJie

#pragma optimize

#include <ansi.h>
#include <net/macros.h>
#include <net/dns.h>

inherit F_DBASE;

#define GEMOTE_Q    "/adm/daemons/network/services/gemote_q"

string remove_addresses(string, int);
int filter_listener(object ppl, string only, object me);

mapping channels = ([ //

    "sys":  ([  "msg_speak": HIR "��"+HIW"ϵͳ"+HIR"��"+BLK"%s��%s\n" NOR,
            "msg_color": BLK,
            "only"     : "wiz",
            "name"     : "ϵͳ",
        ]),

    "qst":  ([  "msg_speak": HIR "��"+HIB"����"+HIR"��"+BLK"%s��%s\n" NOR,
            "msg_color": BLK,
            "only"     : "wiz",
            "name"     : "������",
        ]),

    "err":  ([  "msg_speak": HIR "������%s��%s\n" NOR,
            "msg_color": HIR,
            "only"     : "wiz",
            "name"     : "����",
        ]),

    "adm":  ([  "msg_speak": WHT "���������¡�%s��%s\n" NOR,
            "msg_emote": WHT "���������¡�%s" NOR,
            "msg_color": WHT,
            "only"     : "adm",
            "name"     : "����",
        ]),

    "wiz":  ([  "msg_speak": HIY "����ʦ��%s��%s\n" NOR,
            "msg_emote": HIY "����ʦ��%s" NOR,
            "msg_color": HIY,
            "only"     : "wiz",
            "name"     : "��ʦ",
        ]),

    "debug":([  "msg_speak": HIW "��������Ϣ��"HIR"%s��%s\n" NOR,
            "msg_color": HIR,
            "name"     : "����",
            "only"     : "wiz",
        ]),

    "chat": ([  "msg_speak": HIC "��"HIG"̸��˵��"HIC"��%s��%s\n" NOR,
            "msg_emote": HIC "��"HIG"̸��˵��"HIC"��%s" NOR,
            "msg_color": HIC,
            "name"     : "����",
        ]),

    "sldh": ([  "msg_speak": HIC "��"HIM"ˮ½���"HIC"��%s��%s\n" NOR,
            "msg_emote": HIC "��"HIM"ˮ½���"HIC"��%s" NOR,
            "msg_color": HIC,
            "name"     : "ˮ½���",
        ]),

    "job":  ([  "msg_speak": CYN "��"RED"������"CYN"��%s��%s\n" NOR,
            "msg_color": CYN,
            "name"     : "����",
            "for_listen": 1,
            "anonymous": "ĳ��",
        ]),

    "mete": ([  "msg_speak": WHT "��"YEL"Ʈ������"WHT"��%s��%s\n" NOR,
            "msg_emote": WHT "��"YEL"Ʈ������"WHT"��%s" NOR,
            "msg_color": WHT,
            "name"     : "�ֻ�",
        ]),

    "rumor":([  "msg_speak": HIM "��"HIW"ҥ�Դ�˵"HIM"��%s��%s\n" NOR,
            "msg_emote": HIM "��"HIW"ҥ�Դ�˵"HIM"��%s" NOR,
            "msg_color": HIM,
            "name"     : "ҥ��",
            "for_listen": 1,
            "anonymous": "ĳ��",
        ]),

    "bill": ([  "msg_speak": YEL "��ת�ֽ��ס�%s��%s\n" NOR,
            "msg_color": YEL,
            "name"     : "����",
            "name_raw" : 1,
        ]),

    "party":([  "msg_speak": HIG "�����ɡ�%s��%s\n" NOR,
            "msg_emote": HIG "�����ɡ�%s" NOR,
            "msg_color": HIG,
            "only"     : "party",
            "name"     : "����",
            "filter"   : 1,
        ]),

    "gwiz": ([  "msg_speak": HIG "��������ʦ��%s��%s\n" NOR,
            "msg_emote": HIG "��������ʦ��%s" NOR,
            "msg_color": HIG,
            "intermud" : GCHANNEL,
            "intermud_emote"   : 1,
            "intermud_channel" : "gwiz",
            "name"     : "������ʦ",
            "name_raw" : 1,
            "filter"   : 1,
            "only"     : "wiz",
//                      "filter": (:$1["MUDLIB"]=="SanJie" :) ]),
        ]),
    "sj"  : ([  "msg_speak": HIR "��"HIW"��������"HIR"��%s��%s\n" NOR,
            "msg_emote": HIR "��"HIW"��������"HIR"��%s" NOR,
            "msg_color": HIR,
            "intermud" : GCHANNEL,
            "intermud_emote"   : 1,
            "intermud_channel" : "sj",
            "name"     : "����",
//129              "name_raw" : 1,
            "filter"   : 1,
        ]),
]);

void create()
{
    // This is required to pass intermud access check.
    seteuid(getuid());
    set("channel_id", "Ƶ������");
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
    object *obs, *obswiz;
    string *tuned_ch, who, msg, msgwiz;
    int is_player;
    string imsg = 0, local;
    string party;
	int block_time = 3600;

    // Check if this is a channel emote.
    if (sizeof(verb) > 2)
    {
        if (verb[sizeof(verb) - 1] == '*')
        {
            emote = 1;
            verb = verb[0..<2];
        }
    }

    // Check if this is a channel messsage.
    if (! mapp(channels) || undefinedp(channels[verb])) return 0;

    is_player = playerp(me);
    if ( is_player && ! wizardp(me))
    {
        // player flood...mudring
        if (arg && strlen(arg) > 126)
        {
                arg = arg [0..125];
        }

/*
        if (me->query("mud_age") < 600)
            return notify_fail("�������ע�����ʮ�����Ժ����ʹ�ù���Ƶ�������"
                       "ʱ���������Ķ�����(help newbie)��\n");
*/

        if (verb == "sj" && me->query("age") < 16)
            return notify_fail("���������Ժ����ʹ��" + channels[verb]["name"] +
                       "Ƶ����\n");
    }

    // now we can be sure it's indeed a channel message:
        if (verb == "sj" && me->query("is_pet"))
            return notify_fail("ʲô����\n");
    if (! stringp(arg) || arg == "" || arg == " ")
    {
                arg = "...";
                if (emote) arg = "��������ز�֪����˵Щʲô��\n";
        }

    // player broadcasting need consume jing
    if (userp(me) && ! wizardp(me) && verb == "rumor" )
    {
        if (me->query("sen") > 100)
            me->add("sen", -50);
        else
            return notify_fail("���Ѿ�û����ɢ��ҥ���ˣ�\n");
    }

    if (userp(me) && me->ban_say(1)) return 0;

    // check if one can write to channels
    if ((int)me->query("channel/chblk_all"))
        return notify_fail("�������Ƶ�������ر��ˣ�\n");

    if ((int)me->query("channel/chblk_"+verb) > time() && verb )
        return notify_fail("�Բ������" + channels[verb]["name"] + "Ƶ�����ر��ˣ�\n");

    if (me->query("doing") == "scheme")
            return notify_fail("�����ڵĴ��ڼƻ�֮�У���һ����ɡ�\n");

    if (userp(me))
    {
        switch (channels[verb]["only"])
        {
        case "wiz":
            if (wiz_level(me) < 1)
                return 0;
            break;

        case "adm":
            if (wiz_level(me) < 5)
                return 0;
            break;

        case "party":
            if (! (party = me->query("party/party_name")))
                return notify_fail("�㻹���ȼ���һ��������˵�ɡ�\n");

            if (strlen(party) == 6)
            {
                party = party[0..1] + " " +
                    party[2..3] + " " +
                    party[4..5];
            }
            channels[verb]["msg_speak"] = HIG "��" + party +
                              "��%s��%s\n" NOR;
            channels[verb]["msg_emote"] = HIG "��" + party +
                              "��%s" NOR;
            break;
        }
#define SJ 1        
#ifdef SJ
        if (!wizardp(me))
        {
            int t = uptime();

            if (strlen(arg) > 5)
//            if (!semote && strlen(arg) > 5)
                if (arg[0] >= ' ' && stringp(me->query_temp("last_channel_msg"))
                    && strlen(me->query_temp("last_channel_msg")) > 5
                    && (me->query_temp("last_channel_msg")[0..2] == arg[0..2]
                    || me->query_temp("last_channel_msg")[<3..<1] == arg[<3..<1]))
                me->add_temp("channel_repeat", 1);
            else if (me->add_temp("channel_repeat", -1) < 0)
            {
                if (me->query_temp("robottest") < t-1200)
                    me->add_temp("robottest", 20);
                me->delete_temp("channel_repeat");
            }
		if (verb == "rumor")
		{
			block_time = 86400;
		}
        if (me->query_temp("channel_repeat") > 3)
        {
            me->delete_temp("channel_repeat");
            me->set("channel/chblk_"+verb, time() + block_time);
            do_channel(this_object(), "rumor",
                "���ڽ���̫���£�" + me->query("name")
                +"("+capitalize(me->query("id"))+")��" + channels[verb]["name"] + "Ƶ����ҭ���ˡ�");
        } else if (me->add_temp("channel_count", 1) > 1)
        {
            me->delete_temp("channel_count");
            if (me->query_temp("last_channel_time") == t)
            {
                me->set("channel/chblk_"+verb, time() + block_time);
                do_channel(this_object(), "rumor",
                    "���ڽ���̫��̫�죬" + me->query("name")
                    +"("+capitalize(me->query("id"))+")��" + channels[verb]["name"] + "Ƶ����ҭ���ˡ�");
            }
            me->set_temp("last_channel_time", t);
        }
        me->set_temp("last_channel_msg", arg);
    }
#endif
#ifdef XYJ
        int time, count, last_chat, count1;
        //temporary block chat flooding.
        time = time();
        if ((me->query("channel/chat_block") && (time-me->query("channel/chat_block"))<0 ))
            return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");

        count=me->query("channel/chat_count");
        count1=sizeof(explode(" "+arg,"\n"))/3+1;
        count1+=sizeof(arg)/200;
        count+=count1;
        last_chat=me->query("channel/last_chat");
        if (count>2)
        {
            count=0;
            me->set("channel/last_chat",time);
            if (time==last_chat || count1>2)
            {
                me->set("channel/chat_block",time+180);
                return notify_fail("��Ϊһ�ν���̫�࣬��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");
            }
        }

        me->set("channel/chat_count",count);
#endif
/*
        if (arg == me->query_temp("last_channel_msg"))
            return notify_fail("�ù���Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��\n");
#ifdef HELL
        if (time() - me->query_temp("last_use_channel") < 3)
                return notify_fail("��ɤ���е��ơ�\n");
        else
#endif
        {
            me->set_temp("last_channel_msg", arg);
            me->set_temp("last_use_channel", time());
        }
*/
    }


    // If we speaks something in this channel, then must tune it in.
    if (userp(me))
    {
        if (! pointerp(tuned_ch = me->query("channels")))
        {
            me->set("channels", ({ verb }));
            write("�����" + channels[verb]["name"] + "Ƶ����\n");
        } else
        if (member_array(verb, tuned_ch) == -1)
        {
            me->set("channels", tuned_ch + ({ verb }));
            write("�����" + channels[verb]["name"] + "Ƶ����\n");
        }

        if (wiz_level(me) < channels[verb]["for_listen"])
        {
            write("���Ƶ��ֻ��������ȡ���˵Ľ�̸��\n");
            return 1;
        }
    }

    if (metep(me))
    {
        if (verb == "chat" && ! me->query("env/no_automete"))
            verb = "mete";
    } else
    if (is_player && verb == "mete")
            return notify_fail("�����ֻ�ת������ʹ�����Ƶ���ɣ�\n");

    // Support of channel emote
    if (emote && me->is_character())
    {
        string vb, emote_arg, mud;

        if (undefinedp(channels[verb]["msg_emote"]))
            return notify_fail("���Ƶ����֧�ֱ��鶯�ʡ�\n");

        if (sscanf(arg, "%s %s", vb, emote_arg) != 2)
        {
            vb = arg;
            emote_arg = "";
        }

        // internet channel emote
        if (channels[verb]["intermud_emote"])
        {
            if (sscanf(emote_arg, "%s@%s", emote_arg, mud) == 2 &&
                htonn(mud) != mud_nname())
            {
                GEMOTE_Q->send_msg(channels[verb]["intermud_channel"], me, vb, emote_arg, mud, channels[verb]["filter"]);
                return 1;
            }

            local = sprintf("%s(%s@%s)", me->name(1), capitalize(me->query("id")),
                             upper_case(INTERMUD_MUD_NAME));
            imsg = EMOTE_D->do_emote(me, vb, emote_arg, 3, local,
                         channels[verb]["msg_color"]);
            if (stringp(imsg))
                arg = replace_string(imsg, local, me->name());
            else
                arg = 0;
        } else
        if (verb == "rumor" && random(100) >10)
            arg = EMOTE_D->do_emote(me, vb, emote_arg, 2,
                    channels[verb]["anonymous"],
                    channels[verb]["msg_color"]);
        else
            arg = EMOTE_D->do_emote(me, vb, emote_arg, 1,
                    0, channels[verb]["msg_color"]);

        if (! arg && emote == 2)
            arg = (channels[verb]["anonymous"] ? channels[verb]["anonymous"]
                               : me->name(channels[verb]["name_raw"])) +
                                 vb + "\n";
        if (! arg)
            return 0;
    }

    // Make the identity of speaker.
    if (channels[verb]["anonymous"] && (random(100) >10 || !userp(me)))
    {
        who = channels[verb]["anonymous"];
    } else
    if (is_player || ! stringp(who = me->query("channel_id")))
    {
        who = me->name(channels[verb]["name_raw"]);
        if (who == me->name(1))
            who += channels[verb]["msg_color"] +
                   "(" + capitalize(me->query("id")) + ")";
        if (who[0] == 27) who = NOR + who;
        who += channels[verb]["msg_color"];
    }

    // Ok, now send the message to those people listening us.
    obs = users();
    if (stringp(channels[verb]["only"]))
        obs = filter_array(obs, (: filter_listener :),
                   channels[verb]["only"], me);

    if (! stringp(arg) || arg == "" || arg == " ")
    {
                arg = "...";
                if (emote) arg = "��������ز�֪����˵Щʲô��\n";
        }
    if (emote)
    {
        string localmsg = arg;
        string ecol = channels[verb]["msg_color"];
        if (emote == 2 && ! arg)
            arg = me->name(channels[verb]["name_raw"]) +
                  ecol + "[" + me->query("id") + "@" +
                  INTERMUD_MUD_NAME + "]" + arg + "\n";
        if (! stringp(arg)) return 0;

        if (channels[verb]["msg_emote"])
            localmsg = remove_addresses(arg, 0);

        if (channels[verb]["omit_address"])
            localmsg = remove_addresses(arg, 1);
        else
        if (channels[verb]["intermud_emote"])


        if (! stringp(localmsg)) return 0;

        msgwiz = sprintf(channels[verb]["msg_emote"],
                  sprintf("(" + capitalize(getuid(me)) + ")" + localmsg, ecol, ecol, ecol));
        msg = sprintf(channels[verb]["msg_emote"],
                  sprintf(localmsg, ecol, ecol, ecol));
    } else
    {
        msg = sprintf(channels[verb]["msg_speak"], who, arg);
        if (userp(me) && !channels[verb]["name_raw"]
            && (me->name(1) != me->name() || verb == "rumor"))
        {
            who = "(" + capitalize(getuid(me)) + ")" + who;
        }
        msgwiz = sprintf(channels[verb]["msg_speak"], who, arg);
    }

    obswiz = filter_array( obs ,(: wizardp($1) :));
    obs -= obswiz;

    message("channel:" + ((verb == "mete") ? "chat" : verb), msgwiz, obswiz);
    message("channel:" + ((verb == "mete") ? "chat" : verb), msg, obs);

    if (! undefinedp(channels[verb]["intermud"]) && me->is_character())
    {
        channels[verb]["intermud"]->send_msg(channels[verb]["intermud_channel"],
                             me->query("id"), me->name(1),
                             imsg ? imsg : arg, emote,
                             channels[verb]["filter"]);
    }

    return 1;
}

int filter_listener(object ppl, string only, object me)
{
    // Don't bother those in the login limbo.
    if (! environment(ppl)) return 0;

    switch (only)
    {
    case "adm":
        return (wiz_level(ppl) >= 5);

    case "wiz":
        return (wiz_level(ppl) >= 1);

    case "party":
        return (wizardp(ppl)
            || ppl->query("party/party_name") == me->query("party/party_name"));
    }

    return 1;
}

string remove_addresses(string msg, int all)
{
    int i;
    mixed tmp;
    string pattern;

    if (! stringp(msg)) return msg;
    if (all)
        pattern = "[(][A-Za-z]+@[a-zA-Z]+[0-9]+[.]?[)]";
    else
        pattern = "[(][A-Za-z]+@" + INTERMUD_MUD_NAME + "[)]";

    tmp = reg_assoc(msg, ({ pattern }), ({ 1 }));

    if (! arrayp(tmp)) return msg;
    msg = "";
    for (i = 0; i < sizeof(tmp[0]); i++)
        if (tmp[1][i] == 0) msg += tmp[0][i];
    return msg;
}
