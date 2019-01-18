//transter.c
//by xiaofeng

#include <ansi.h>
#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
void create() { seteuid(ROOT_UID); }

void send_msg(string name, string cname, string file, string backmsg)
{
        mapping minfo;
        string mud;
        mud = htonn(name);
        if(mud == mud_nname()) return;

        minfo = (mapping)DNS_MASTER->query_mud_info(mud);
        if (!minfo) return;
        DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                        "@@@" + "transfer_a" +
                        "||NAME:" + Mud_name() +
                        "||PORTUDP:" + udp_port() +
                        "||FILE:" + file +
                        "||CNAME:" + cname +
                        "||BACKMSG:"+ backmsg + "@@@\n");
}
void incoming_request(mapping info)
{
        string id, name, msg, file, backmsg, localmsg;
        set("channel_id", HIW"[�ļ�����]");
        if (info["BACKMSG"])
        {
                CHANNEL_D->do_channel(this_object(),"wiz",info["CNAME"] + "�����ļ�" + info["FILE"] + "��" + 
                                        HIR + info["NAME"] + HIW + info["BACKMSG"]);
                return;
        }

        return;
}


