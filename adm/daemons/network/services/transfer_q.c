//transter.c
//by xiaofeng

#include <ansi.h>
#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
#define RECEIVE_DIR "/p/receive/"
#define TRANSFER_A "/adm/daemons/network/services/transfer_a.c"
void create() { seteuid(ROOT_UID); }

void send_msg(object me,string mud,string file,string msg)
{
        mapping minfo;
        if (!file || !msg) return;
        mud = htonn( mud );
        if(mud == mud_nname() || !geteuid(me)) return;

        minfo = (mapping)DNS_MASTER->query_mud_info(mud);
        if (!minfo)
        {
                tell_object(me, "�޴�MUD��δ�ʹ�MUD����!��ʹ��mudlist�鿴!\n");
                return ;
        }
        DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                        "@@@" + "transfer_q" +
                        "||NAME:" + Mud_name() +
                        "||PORTUDP:" + udp_port() +
                        "||ID:" + geteuid(me) +
                        "||CNAME:" + me->query("name") +
                        "||FILE:" + file +
                        "||MSG:"+msg+"@@@\n");
        tell_object(me, "������֤ͨ��,��ȴ�Զ�̼������Ӧ��\n");
}
void incoming_request(mapping info)
{
        mapping minfo;
        string id, name, msg, file, backmsg, localmsg;
        set("channel_id", HIW"[�ļ�����]");
        if (info["NAME"] && info["PORTUDP"]) 
        {
                if (info["NAME"] == Mud_name())   return;

                minfo = DNS_MASTER->query_mud_info(info["NAME"]);
                if (!minfo || !DNS_MASTER->dns_mudp(info["NAME"]))
                        PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
        
                if (minfo && minfo["HOSTADDRESS"] != info["HOSTADDRESS"]) 
                        return ;
                id = info["ID"];
                name = info["CNAME"];
                file = RECEIVE_DIR + info["FILE"];
                msg = info["MSG"];
                if (file_size(RECEIVE_DIR) != -2)
                {
                        localmsg = "��ͼ�����ļ�,���ҷ�δ������Ӧ��RECEIVEĿ¼!" +
                                "��鿴/adm/daemons/network/services/transfer.c�ļ�!";
                        backmsg = "ʧ��,�Է�û�н���RECEIVEĿ¼!";
                        TRANSFER_A->send_msg(info["NAME"], name, file, backmsg);                        
                        CHANNEL_D->do_channel(this_object(), "wiz",name+"("+id+"@"+info["NAME"]+")"+localmsg + NOR + "\n");
        
                        return;
                }
                if( stringp(file) && file!="")
                if (file_size(file) != -1 || file_size(file) == -2 )
                {
                        localmsg = "��ͼ�����ļ�"+file+",�����ļ��Ѿ�����!";
                        backmsg = "ʧ��,�Է�ϵͳ���Ѵ���ͬ���ļ�!";
                        TRANSFER_A->send_msg(info["NAME"], name, file, backmsg);                        
                        CHANNEL_D->do_channel(this_object(), "wiz",name+"("+id+"@"+info["NAME"]+")"+localmsg + NOR + "\n");
                        return;
                }
                msg = info["MSG"];
                if (!msg) return;
                write_file(file, msg);
                if (file_size(file) < 0)
                {
                        localmsg = "��ͼ�����ļ�"+file+"ʧ��,������Ȩ�޲�����!";
                        backmsg = "ʧ��,��������Ȩ��д��Է�RECEIVEĿ¼!";
                        TRANSFER_A->send_msg(info["NAME"], name, file, backmsg);                        
                        CHANNEL_D->do_channel(this_object(), "wiz",name+"("+id+"@"+info["NAME"]+")"+localmsg + NOR + "\n");
                }
                else
                {
                        localmsg = "�����ļ�"+file+"�ɹ�!";
                        backmsg = "�ɹ�!";
                        TRANSFER_A->send_msg(info["NAME"], name, file, backmsg);                        
                        CHANNEL_D->do_channel(this_object(), "wiz",name+"("+id+"@"+info["NAME"]+")"+localmsg + NOR + "\n");
                }
                
                return;    
        }
}

